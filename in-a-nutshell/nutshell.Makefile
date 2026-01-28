# Comment

# See other quick reference documentation here:
# https://www.gnu.org/software/make/manual/html_node/Quick-Reference.html

# Declare variables:
FOO = 0 # can be reference with $() or ${} (no differences).

BAR_0  = ${FOO} # expands FOO every BAR_0 is used. Changing
                # FOO value will change BAR_0 value.

BAR_1 := ${FOO} # expands FOO during the attribution.
                # Changing FOO value will NOT change
                # BAR_1 value.

BAR_2 ?= ${FOO} # equals `=`, but it only will attribute
                # the value if BAR_2 does not have a value.

BAR_0 += ${FOO} # concatenates the values, and separates
                # them with one space character.


# `wildcard` is a FUNCTION that expands `*`/`**`, if it is
# not used `*` will be treated as a normal character.
#
# Makefile DOES NOT allow custom functions.
SRC_FILE := $(wildcard ./**/*.foo)


# Pre-processing rules:
ifdef FOO
  $(warning "I'm a warning message.")
else
  $(error "I'm an ERROR message!")
endif

#ifeq '$(FOO)' '10'
#ifeq "$(FOO)" "10"
ifeq ($(FOO), "10")
  $(info "FOO is equal 10!")
endif

# `ifndef`, and `ifneq` are
# available too.


# Rules (they are executed after all files is read):
#
# target: what will be created (file or directory).
# dependences: what is required by "target", and
#              that must be created before.
# #commands: set of commands (prefixed by ONE tabulation)
#            to be executed by system shell. Prefix
#            command with `@`, like `@echo`, will hide
#            it, during `make` execution.
target: dependence
	#commands
	# We're a SHELL comment!

dependence:
	# Targets supports the "Automatic variables", they
	# are special variables used to get specific values.
	# The main are:
	#
	# $@ : target name, or library name if the target is
	#      an archive member reference.
	# $% : target name, or object name if target is an
	#      archive member reference.
	# $< : first dependence.
	# $? : all dependences newer than the "target", with
	#      spaces between them.
	# $^ : all dependences, with spaces between them. It
	#      removes duplicates.
	# $+ : equals $^, but it maintains the items order,
	#      and does not remove duplicates
	# $| : list dependences required to run the rule, but
	#      it does not force its update.
	# $* : "stem" of a target that use `%` (wildcard),
	#      e.g.: `%`, of `%.c`, is "./src/main", so
	#      $* is "./src/main".

# Special variable used to store the name of targets
# that are not file, nor directories. Commonly it
# is used to store: `all`; `test`; and `clean`.
.PHONY: target dependence

