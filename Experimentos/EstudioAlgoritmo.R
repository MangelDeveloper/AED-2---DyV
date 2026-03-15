tiempoPeor <- read.csv("tiempoPeor.txt", header = TRUE)
tiempoMejor <- read.csv("tiempoMejor.txt", header = TRUE)


medianas_peor <- c(
  median(tiempoPeor$i0),
  median(tiempoPeor$i1),
  median(tiempoPeor$i2),
  median(tiempoPeor$i3),
  median(tiempoPeor$i4),
  median(tiempoPeor$i5),
  median(tiempoPeor$i6),
  median(tiempoPeor$i7),
  median(tiempoPeor$i8),
  median(tiempoPeor$i9),
  median(tiempoPeor$i10)
)

medianas_mejor <- c(
  median(tiempoMejor$i0),
  median(tiempoMejor$i1),
  median(tiempoMejor$i2),
  median(tiempoMejor$i3),
  median(tiempoMejor$i4),
  median(tiempoMejor$i5),
  median(tiempoMejor$i6),
  median(tiempoMejor$i7),
  median(tiempoMejor$i8),
  median(tiempoMejor$i9),
  median(tiempoMejor$i10)
)

n_vector = rep(0,11)
for(i in 0:10){
  n_vector[i+1] = 1000*(2^i)
}

# --- Nube de puntos superpuesta ---
plot(n_vector, medianas_peor,
     main = "Peor vs Mejor Caso",
     xlab = "Iteración i de n = 1000 * 2^i",
     ylab = "Mediana del Tiempo (μs)",
     pch = 19,
     col = "blue",
     ylim = range(c(medianas_mejor, medianas_peor)))  # ajustar rango Y

points(n_vector, medianas_mejor,
       pch = 19,
       col = "green")  # nube de puntos del mejor caso en verde

legend("topleft",
       legend = c("Peor Caso", "Mejor Caso"),
       col = c("blue", "green"),
       pch = 19)

modelo_peor <- lm(medianas_peor ~ n_vector)
modelo_mejor <- lm(medianas_mejor ~ n_vector)

abline(modelo_peor)
abline(modelo_mejor)

r_cuadrado_peor = summary(modelo_peor)$r.squared
r_cuadrado_mejor = summary(modelo_mejor)$r.squared

c(r_cuadrado_peor=r_cuadrado_peor,r_cuadrado_mejor=r_cuadrado_mejor)
