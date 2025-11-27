# Use a lightweight Debian-based C++ image
FROM mcr.microsoft.com/devcontainers/cpp:1-debian-11

# Install additional tools if needed
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    cmake \
    build-essential \
    gdb \
    git \
    doxygen \
    graphviz \
    && apt-get clean -y && rm -rf /var/lib/apt/lists/*