#!/bin/bash


# Random WallPaper to lxqt
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
ran=-2
last=-2

# based
len=${#img[@]}


# check if valued specified are valid
error(){
	$_ECH "$name $1"
	exit 1
}

if [ ! -d "$path" ]; then
	error "invalid path (#3)."
fi

if [ $len -eq 0 ]; then
	error "images not specified."
fi

for cur in "${img[@]}"; do
	if [ ! -f "$path$cur" ]; then
		error "an nonexistent image was specified: $path$cur."
	fi
done

if ! command -v "$_PCM" > /dev/null 2>&1; then
	error "\"pcmanfm(-qt)\" not found."
fi


# create/open save file
if [ ! -e "$save" ]; then
	$_ECH -1 > "$save"
fi

last=$($_CAT "$save")

if ! [[ "$last" =~ ^⁻?[0-9]+$ ]]; then
	last=-1
fi


# set wallpaper
if [ $len -eq 1 ]; then
	len=1
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
