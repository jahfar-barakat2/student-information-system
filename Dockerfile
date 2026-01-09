# ==========================================
# STAGE 1: Development & Builder 
# ==========================================
FROM ubuntu:24.04 AS builder

ARG DEBIAN_FRONTEND=noninteractive

# Install dependencies required for C++ and Libpqxx 

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libpq-dev \
    libpqxx-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    make -j$(nproc)


# ==========================================
# STAGE 2: Production 
# ==========================================
FROM ubuntu:24.04 AS production

# Install ONLY runtime libraries
RUN apt-get update && apt-get install -y \
    libpqxx-dev \
    libpq-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy ONLY the compiled binary from the builder stage
# (Assuming you run 'make' in the builder stage first)
COPY --from=builder /app/build/StudentSystem .

# This keeps the container alive for interaction.
CMD ["./StudentSystem"]