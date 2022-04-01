FROM ubuntu
COPY lb3_3.cpp .
RUN apt-get update
RUN apt-get install -y gcc
RUN apt-get install -y g++
RUN g++ lb3_3.cpp -static
CMD ./a.out
