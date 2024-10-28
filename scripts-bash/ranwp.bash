#!/bin/bash


# Random WallPaper to lxqt (v0.1.1)
# MIT License
#
# Copyright (c) 2024 DuckAfire <facebook.com/duckafire>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.


# error codes
# 0 - operation sucessed
# 1 - command not founded or there is not permission to execute it
# 2 - no permission to write or read the save file
# 3 - path (directory) or file (image) does not exist


# arguments
path="$1"
img=("${@:2}")


# "commands" used:
_CAT="cat"
_PCM="pcmanfm-qt"
_ECH="echo"


# default
name="[ ranwp ]"
save="$HOME/.ranwp-sh"
ran=-1
last=-1


# based in
len=${#img[@]}


# functions
error(){
	$_ECH "$name $2."
	exit $1
}
canExec(){
	if ! command -v "$1" &> /dev/null; then
		error 1 "command not found (or you cannot have permission to execute it): $1"
	fi
}
sfm(){ # Save File Message
	error 2 "you do not have permission to $1 the save file ($save)"
}


# check permissions
canExec $_CAT
canExec $_PCM
canExec $_ECH


# check if valued specified are valid
if [ ! -d "$path" ]; then
	error 3 "invalid path (#3)"
fi

if [ $len -eq 0 ]; then
	error 3 "images not specified"
fi

for cur in "${img[@]}"; do
	if [ ! -f "$path$cur" ]; then
		error 3 "a nonexistent image was specified: $path$cur"
	fi
done


# create/open save file
if [ ! -e "$save" ]; then
	$_ECH "-1" > "$save"
elif [ ! -r "$save" ]; then
	sfm "read"
elif [ ! -w "$save" ]; then
	sfm "write to"
fi

last=$($_CAT "$save")

if ! [[ "$last" =~ ^-?[0-9]+$ ]]; then
	last=-1
fi


# set wallpaper
if [ $len -eq 1 ]; then
	len=0
	$_ECH "0" > "$save"
else
	while true; do
		ran=$((RANDOM % $len))
		if [ "$ran" -ne "$last" ]; then
			$_ECH "$ran" > "$save"
			break
		fi
	done
fi

$_PCM --set-wallpaper "$path${img[$ran]}"

# cleanup
unset path img
unset _CAT _PCM _ECH
unset name save ran last
unset len
unset -f error canExec sfm
