FROM ubuntu:24.04

# Set environment variables to avoid interactive prompts
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=UTC

# Update package lists and install system dependencies
RUN apt-get update && apt-get install -y \
    # Build tools
    build-essential \
    cmake \
    git \
    # Python
    python3 \
    python3-pip \
    python3-dev \
    # Verilator dependencies
    perl \
    make \
    autoconf \
    g++ \
    flex \
    bison \
    ccache \
    libgoogle-perftools-dev \
    numactl \
    perl-doc \
    # Additional utilities
    wget \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Install Verilator from official repository
RUN apt-get update && apt-get install -y verilator \
    && rm -rf /var/lib/apt/lists/*

# Verify Verilator installation
RUN verilator --version

# Set work directory
WORKDIR /app

# Create non-root user for security
RUN useradd -m veridev && \
    chown -R veridev:veridev /app
USER veridev

# Copy requirements first for better Docker layer caching
COPY --chown=veridev:veridev requirements.txt .

# Install Python dependencies
RUN pip3 install --user --no-cache-dir -r requirements.txt

# Add user's pip bin to PATH
ENV PATH="/home/veridev/.local/bin:$PATH"

# Copy application code
COPY --chown=veridev:veridev . .

# Set Python path
ENV PYTHONPATH=/app

# Create output directory
RUN mkdir -p /app/output

# Expose port for web API
EXPOSE 8000

# Health check
HEALTHCHECK --interval=30s --timeout=30s --start-period=5s --retries=3 \
    CMD curl -f http://localhost:8000/health || exit 1

# Default command - can be overridden
CMD ["python3", "-m", "veridev.veridev", "--web"]
