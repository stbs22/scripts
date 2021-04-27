# Resumen
#
# d___ : exact probability P(X=x) = ??
# p___ : acum probability P(X<=x) = ??
# q___ : quantile probability P(X<=??) = y
# r___ : random numbers that follows the distribution
# "___" reference to: normal, binomial, poisson, gamma, etc. 
#  
#
# 
# Distribución gamma
# 
# E[x] = alpha * beta
# Var[x] = alpha * beta^2
# ---------------------------------
# 
# Distribución Weibull
# 
# E[x] = lambda * gamma(1+1/k)
# Var[x] = ...
# ---------------------------------
# 
# Distribución Lognormal
# 
# E[x] = exp(mu + (sigma^2)/2)
# Var[x] = exp(2mu + sigma^2)*(exp(sigma^2) - 1)
# ---------------------------------
  

##ACTIVIDAD 1

#gamma(alpha = 3, beta = 2)
norm

# A)

#Teórico
3*2 #mean of gamma (3,2)
3*(2^2) #variance of gamma(3,2)

#Empírico
gamma_sim <- rgamma(170, 3, scale = 2)
mean(gamma_sim) #mean of gamma(3,2) sample
var(gamma_sim) #variance of gamma(3,2) sample



# B)    P(X>2)

pgamma(q = 2, shape = 3, scale = 2, lower.tail = FALSE) #theorical probability
length(which(gamma_sim > 2))/170 #empirical probability of 170 sample




##ACTIVIDAD 2

#weibull(k=3, lambda=8) 

# A)

#Teórico
8*gamma(1 + 1/3) #mean of weibull (3,8)


#Empírico
weib_sim <- rweibull(500, shape = 3, scale = 8)
mean(weib_sim) #mean of weibull (3,8) sample



# B)    P(X<6) = P(X<=6)
pweibull(6, shape = 3, scale = 8, lower.tail = TRUE) #theorical probability
length(which(weib_sim <= 6))/500 #empirical probability of 500 sample





##ACTIVIDAD 3

#log-normal(mu = 5, sig = 0.2)


# A)

#Teórico
exp(5 + ((0.2)^2)/2) #mean of log-norm(5,0.2)
exp(2*5 + (0.2^2))*(exp(0.2^2)-1) #variance of log-norm(5,0.2)

#Empírico
log_norm_sim <- rlnorm(300, meanlog = 5, sdlog = 0.2)
mean(log_norm_sim) #mean of log-norm(5,0.2) sample
var(log_norm_sim) #variance of log-norm(5,0.2) sample



# B)   P(X<150) = P(X<=150)
plnorm(150, meanlog = 5, sdlog = 0.2, lower.tail = TRUE) #theorical probability
length(which(log_norm_sim < 150))/300 #empirical probability of 300 sample




#plot example
par(mfrow=c(2, 2))
hist(gamma_sim, breaks = seq(min(gamma_sim), max(gamma_sim), by = (max(gamma_sim)-min(gamma_sim))/nclass.Sturges(gamma_sim)), probability = T)
lines(density(gamma_sim))
hist(weib_sim, breaks = seq(min(weib_sim), max(weib_sim), by = (max(weib_sim)-min(weib_sim))/nclass.Sturges(weib_sim)), probability = T)
lines(density(weib_sim))
hist(log_norm_sim, breaks = seq(min(log_norm_sim), max(log_norm_sim), by = (max(log_norm_sim)-min(log_norm_sim))/nclass.Sturges(log_norm_sim)), probability = T)
lines(density(log_norm_sim))

