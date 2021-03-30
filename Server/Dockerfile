FROM gcc:9.2

WORKDIR /app

ADD ./serversrc /server
RUN cd /server && make

ADD ./src /app
