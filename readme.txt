Use: reverse some stream of text

Example: 

    input.txt:  Hello, World!
                This is an Example
    
    reverse input.txt:  This is an Example
                        Hello, World!

So the file is broken up into "lines". A "line" is essentially a sequence of chars that ends with a newline or EOF.
So I'm just gonna use getline() actually I just read the man page and it's exactly what I need.