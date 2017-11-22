 #include <sys/types.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>



 void
 read_from_pipe (int file)
 {
   FILE *stream;
   int c;
   stream = fdopen (file, "r");
   while ((c = fgetc (stream)) != EOF)
     putchar (c);
    
   fclose (stream);

   write_to_pipe(c,file); 
  }


 int
 write_to_pipe (int c,int file)
 {
   FILE *stream;
   int i;
   stream = fdopen (file, "w");
   for(i=0 ; i<25 ; i++)
   {
        c++;
        
     }
   
    char *num;
  
    snprintf(num, 1, "%d", c);

   fprintf (stream, "num");
  
   fclose (stream);
 }

 int
 main (void)
 {
   pid_t pid;
   pid_t pid2;
   int mypipe[2];

   
   if (pipe (mypipe))
     {
       fprintf (stderr, "Pipe failed.\n");
       return EXIT_FAILURE;
     }

   
   
     pid = fork ();
    if (pid ==  0)
     { 
          pid2=fork();  
       
       close (mypipe[1]);
       read_from_pipe (mypipe[0]);
       return EXIT_SUCCESS;
     }
   else if (pid < 0)
     {
       
       fprintf (stderr, "Fork failed.\n");
       return EXIT_FAILURE;
     }
   else
     {
       close (mypipe[0]);
       read_from_pipe (mypipe[1]);
       return EXIT_SUCCESS;
     }
 }
