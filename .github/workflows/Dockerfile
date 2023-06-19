FROM alpine:latest

# Instalar dependências
RUN apk add --no-cache cmake make clang llvm sdl2-dev

# Configurar o diretório de trabalho
WORKDIR /app

# Copiar o código-fonte para o container
COPY . .

# Configurar o processo de compilação
RUN mkdir build && \
    cd build && \
    CC=clang CXX=clang++ cmake .. && \
    make

# Definir o comando de execução (opcional)
CMD ["./build/my_application"]
