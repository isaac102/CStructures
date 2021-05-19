FROM ubuntu:16.04

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install gcc valgrind -y

COPY . /usr/src

WORKDIR /usr/src

RUN gcc -o mem linkedList.c

CMD ["./mem"]
