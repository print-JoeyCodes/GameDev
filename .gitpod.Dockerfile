FROM gitpod/workspace-base:latest

RUN sudo apt-get update && \
    sudo apt-get install -y \
      build-essential \
      cmake \
      git \
      libx11-dev \
      libxrandr-dev \
      libxinerama-dev \
      libxcursor-dev \
      libxi-dev \
      libgl1-mesa-dev \
      libglu1-mesa-dev \
      pkg-config && \
    sudo rm -rf /var/lib/apt/lists/*
