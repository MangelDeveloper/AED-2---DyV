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

n_vector = n_vector <- 1000 * 2^(0:10)

# --- Nube de puntos recta de regresión ---
plot(n_vector, medianas_peor,
     main = "Peor vs Mejor Caso",
     xlab = "Tamaño de entrada n",
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

modelo_peor_uno <- lm(medianas_peor ~ n_vector) #O(n)
modelo_peor_dos <- lm(medianas_peor ~ I(n_vector*log(n_vector))) #O(n*log(n)) <- Orden real del algoritmo
r_cuadrado_peor_uno = summary(modelo_peor_uno)$r.squared #O(n)
r_cuadrado_peor_dos = summary(modelo_peor_dos)$r.squared #O(n*log(n))

modelo_mejor_uno <- lm(medianas_mejor ~ n_vector) #O(n)  <- Orden real del algoritmo
modelo_mejor_dos <- lm(medianas_mejor ~ I(n_vector*log(n_vector))) #O(n*log(n))
r_cuadrado_mejor_uno = summary(modelo_mejor_uno)$r.squared
r_cuadrado_mejor_dos = summary(modelo_mejor_dos)$r.squared

c('Peor O(n)'=r_cuadrado_peor_uno,'Peor O(n*log(n))'=r_cuadrado_peor_dos)
c('Mejor O(n)'=r_cuadrado_mejor_uno,'Mejor O(n*log(n))'=r_cuadrado_mejor_dos)

# --- Nube de puntos recta de regresión ---
plot(n_vector, medianas_peor,
     main = "Peor caso",
     xlab = "Tamaño de entrada n",
     ylab = "Mediana del Tiempo (μs)",
     pch = 19,
     col = "blue",
     ylim = range(c(medianas_mejor, medianas_peor)))  # ajustar rango Y

legend("topleft",
       legend = c("Peor Caso", expression(paste("Ajuste ", Theta(n*log(n))))),
       col = c("blue", "red"),   # colores
       pch = c(19, NA),             # primer punto, segundo nada
       lty = c(NA, 1),              # primer sin línea, segundo línea sólida
       lwd = c(NA, 2))              # grosor de la línea

lines(n_vector, predict(modelo_peor_dos), col="red", lwd=2)

# --- Nube de puntos recta de regresión ---
plot(n_vector, medianas_mejor,
     main = "Mejor caso",
     xlab = "Tamaño de entrada n",
     ylab = "Mediana del Tiempo (μs)",
     pch = 19,
     col = "blue",
     ylim = range(c(medianas_mejor, medianas_peor)))  # ajustar rango Y

legend("topleft",
       legend = c("Mejor Caso", expression(paste("Ajuste ", Theta(n)))),
       col = c("blue", "red"),   # colores
       pch = c(19, NA),             # primer punto, segundo nada
       lty = c(NA, 1),              # primer sin línea, segundo línea sólida
       lwd = c(NA, 2))              # grosor de la línea

lines(n_vector, predict(modelo_mejor_uno), col="red", lwd=2)
