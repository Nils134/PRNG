set.seed(42)
f <- file("stdin")
while(1) {
    open(f, blocking=TRUE)
    if (length(line <- readLines(f,n=1)) > 0) {
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