FROM gcc:9.2

WORKDIR /app

ADD ./serversrc /server
RUN cd /server/YanaPServer && make

ADD ./src /app
