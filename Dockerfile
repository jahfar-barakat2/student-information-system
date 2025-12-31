# ==========================================
# STAGE 1: Development & Builder 
# ==========================================
FROM ubuntu:22.04 AS builder

ARG DEBIAN_FRONTEND=noninteractive

# Install dependencies required for C++ and libpqxx
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    libpq-dev \
    libpqxx-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# To interact with the project in development stage
CMD ["tail", "-f", "/dev/null"]


# ==========================================
# STAGE 2: Production 
# ==========================================
FROM ubuntu:22.04 AS production

# Install ONLY runtime libraries 
RUN apt-get update && apt-get install -y \
    libpqxx-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy ONLY the compiled binary from the builder stage
# (Assuming you run 'make' in the builder stage first)
COPY --from=builder /app/build/StudentSystem .

# In Prod, the app runs immediately
CMD ["./StudentSystem"]