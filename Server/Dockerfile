FROM gcc:9.2

WORKDIR /app

ADD ./serversrc /server
RUN cd /server && make

ADD ./utilsrc /util
RUN cd /util && make

ADD ./src /app

RUN make

CMD ["bin/server.out"]
