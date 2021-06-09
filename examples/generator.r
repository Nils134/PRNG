set.seed(42)
f <- file("stdin")
open(f, blocking=FALSE)
options(scipen = 999)
while(1) {
    
    if (length(line <- readLines(f,ok=TRUE,n=1, skipNul=TRUE)) > 0) {
    for (i in 1:1000000) {
        temp = paste(format(round(runif(1), digits=12), nsmall = 12),"\n",
            format(round(runif(1), digits=12), nsmall = 12),"\n",
            format(round(runif(1), digits=12), nsmall = 12),"\n",
            format(round(runif(1), digits=12), nsmall = 12),"\n",
            sep="")
        cat(temp)
    }
    }
    
}