### Para rodar basta colocar assim no terminal:
    
    gcc naive.c -o naive -fopenmp -lm 
    gcc bag_of_tasks.c -o bag_of_tasks -fopenmp -lm
    

### E depois:

    ./naive {numero desejado} {numero de threads} 
    ./bag_of_tasks {numero desejado} {numero de threads} 