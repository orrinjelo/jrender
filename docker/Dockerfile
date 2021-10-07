FROM frolvlad/alpine-gcc:latest

# Install deps
RUN echo "http://dl-cdn.alpinelinux.org/alpine/v3.13/community" >> /etc/apk/repositories \
  && apk update \
  && apk add --update-cache --no-cache alpine-sdk \
  && apk add --update-cache --no-cache libgcc libquadmath musl \
  && apk add --update-cache --no-cache libgfortran \
  && apk add --update-cache --no-cache lapack-dev \
  && apk add --update-cache --no-cache openblas-dev \
  && apk add --update-cache --no-cache libpng \
  && apk add --update-cache --no-cache cmake

WORKDIR /render
