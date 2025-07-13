# it is a commentary
# You do NOT need the syntax highlight!

# I recommends that you deeping in:
# * Parser directives:   https://docs.docker.com/reference/dockerfile/#parser-directives
# * dockerignore file:   https://docs.docker.com/build/concepts/context/#dockerignore-files
# * Shell and exec form: https://docs.docker.com/reference/dockerfile/#shell-and-exec-form
# * Predefined ARGs:     https://docs.docker.com/reference/dockerfile/#predefined-args
# * ARG & FROM interact: https://docs.docker.com/reference/dockerfile/#understand-how-arg-and-from-interact
# * Scoping:             https://docs.docker.com/build/building/variables/#scoping
# * CMD & ENT. interact: https://docs.docker.com/reference/dockerfile/#understand-how-cmd-and-entrypoint-interact
# * ADD options:         https://docs.docker.com/reference/dockerfile/#add
# * COPY options:        https://docs.docker.com/reference/dockerfile/#copy
# * ADD vs COPY:         https://docs.docker.com/build/building/best-practices/#add-or-copy
# * Volumes:             https://docs.docker.com/engine/storage/volumes/
# * Cont. health tests:  https://docs.docker.com/reference/dockerfile/#healthcheck
# * Here-documents:      https://docs.docker.com/reference/dockerfile/#here-documents


# `?`: A random character.
# `*`: An undefined quantity of random characters.


# It is a convention that:
# * Docker instructions have to use UPPERCASE.
# * Docker directives have to use lowercase.

# Directives and its syntaxes (they must be commentaries "pre-FROM"):
# syntax=<value>
# escape=<value>
# check=<key>=<value>


# set the BASE IMAGE for subsequent instructions
FROM hello-world:linux


# deprecated instruction
# MAINTAINER DuckAfire

# image metadata
LABEL maintainer=DuckAfire


# it can receive a value during the run process;
# available only during the build process
ARG only_declare
ARG set_default_value=foobar

ENV env_available_in="available build process and container env."


# set the default shell of the container (to ENTRYPOINT and CMD)
SHELL ["/usr/bin/env", "bash"]


# directory base of the project, used to fill non-absolute paths
# in: RUN; CMD; ENTRYPOINT; ADD; COPY;
WORKDIR /foobar


# if ENTRYPOINT is not specified, it command will be runned
# when the container is started, otherwise its contant will
# be used as argument to ENTRYPOINT
CMD ["echo", "-e", "Hello world!"]

# it can have itself arguments too
ENTRYPOINT ["echo"]

# override the last values (group of is values single)
CMD ["-e", "Hello world!"]


# run during the build process; create and commit a new
# layer with the applied changes (save it in the cache);
# all calls are executed
RUN mkdir /tmp-foobar \
	&& rmdir /tmp-foobar


# "tcp" is default; listing in:
EXPOSE 8080
EXPOSE 8080/udp


# ADD <src0> [srcN] <dest>
# ADD file.txt /app/files/
# ADD files.tar.gz /app/files/
# ADD https://example.com/file.txt /app/files/
# ADD git@github.com:user/repo.git /app/files/


# COPY <src0> [srcN] <dest>


# set what user must run the container commands
# (it must be created previously or in the Dockerfile)
# USER <user>[:group]
# USER <UID>[:GID]


# these instructions will be runned when a container, based this,
# it will be created, before this, they are "sleeping"
ONBUILD RUN echo "This is a child!"
ONBUILD ENTRYPOINT ["echo", "-e"]
ONBUILD CMD ["\tfoobar\n"]
# it do not work with: ONBUILD; FROM; MAINTAINER


# it defines what system call signal will kill the container
# (default is `SIGTERM`)
STOPSIGNAL SIGTERM


# set who the Docker must test the container is working
# HEALTHCHECK NONE
HEALTHCHECK --interval=5m --timeout=3s \
	CMD curl -s https://example.com &> /dev/null || exit 1
