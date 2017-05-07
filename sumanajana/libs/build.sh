# Build all the test libraries

echo "Building tinyuntar..."

echo "Building upng..."

echo "Building OpenSSL..."
url="https://www.openssl.org/source/openssl-1.1.0e.tar.gz"

echo "Building zlib..."
url="http://www.zlib.net/zlib-1.2.11.tar.gz"

tar -xzf zlib-1.2.11.tar.gz
rm zlib-1.2.11.tar.gz

cd zlib-1.2.11
# Apply patch
CC=../../../afl-gcc CFLAGS="-g -Wall -O2" ./configure
make -j8
