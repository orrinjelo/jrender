FROM frolvlad/alpine-gcc:latest

# Install deps
RUN echo "http://dl-cdn.alpinelinux.org/alpine/v3.13/community" >> /etc/apk/repositories \
  && apk update \
  && apk add --update-cache --no-cache alpine-sdk \
  && apk add --update-cache --no-cache libgcc libquadmath musl \
  && apk add --update-cache --no-cache libgfortran \
  && apk add --update-cache --no-cache lapack-dev \
  && apk add --update-cache --no-cache openblas-dev \
  && apk add --update-cache --no-cache libpng-dev \
  && apk add --update-cache --no-cache cmake \
  && apk add --update-cache --no-cache boost-dev

RUN cd /opt \
  && wget http://download.savannah.nongnu.org/releases/pngpp/png++-0.2.9.tar.gz \
  && tar xvf png\+\+-0.2.9.tar.gz \
  && cd png\+\+-0.2.9/ \
  && PREFIX=/usr make install-headers

WORKDIR /render
