#FROM ubuntu:16.04

#RUN apt-get update
#RUN apt-get upgrade -y
#RUN apt-get install gcc valgrind -y

#COPY . /usr/src

#WORKDIR /usr/src

#RUN gcc -o mem binaryTree.c
#RUN gcc -g -Og -std=gnu99 -o mem binaryTree.c

#CMD ["./mem"]

#-----------------------------------------------------
FROM debian:stretch

MAINTAINER Ryan Moore <moorer@udel.edu>

# Update package manager
RUN apt-get update
RUN apt-get upgrade -y

# Has stuff like gcc, make, and libc6-dev
RUN apt-get install -y build-essential

# Valgrind!
RUN apt-get install -y valgrind

# Run it as if it were valgrind
ENTRYPOINT ["valgrind"]
CMD ["--help"]