# ============================
# ETAP 1: BUDOWANIE (Alpine)
# ============================
FROM alpine:latest AS builder

# Instalacja kompilatora i bibliotek do budowania
RUN apk add --no-cache g++ make

WORKDIR /app
COPY . .

# Kompilacja
RUN g++ -O2 -o app aplikacja.cpp


# ============================
# ETAP 2: MINIMALNY RUNTIME (Alpine)
# ============================
FROM alpine:latest AS runtime

WORKDIR /app

# Kopiujemy skompilowany binarny plik
COPY --from=builder /app/app /app/app

# Instalujemy libstdc++ (niezbędna dla C++)
RUN apk add --no-cache libstdc++

CMD ["./app"]
