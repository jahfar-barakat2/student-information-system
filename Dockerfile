FROM ubuntu:22.04

RUN apt-get update && \
    apt-get install -y g++ make libpq-dev libpqxx-dev

WORKDIR /app

COPY . .

RUN g++ -std=c++17 src/main.cpp -lpqxx -lpq -o app

CMD ["./app"]