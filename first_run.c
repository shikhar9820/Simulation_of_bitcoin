#include<sys/stat.h>                //for mkdir()
#include<string.h> 
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>                   //for errno and error values
#include"betacoin.h"

 char static_path[FOLDER_SIZE];


int main()
{
 FILE *fp;
 char tempname[101];

 system("rm -rf ~/betacoin");

/*--CHECK PYTHON----------------------------------------------------------*/ 
 if(system("python3 -V") != 0)
 {
  line();
  printf("\n\n\tERROR: CANNOT RUN python3. CHECK IF IT IS INSTALLED OR FOR OTHER ERRORS.\n");
  line();
  exit(1);
  }
 
/*--CHECK GCC----------------------------------------------------------*/ 
 if(system("gcc -v") != 0)
 {
  line();
  printf("\n\n\tERROR: CANNOT RUN gcc. CHECK IF IT IS INSTALLED OR FOR OTHER ERRORS.\n");
  line();
  exit(1);
  }

/*--MAKE FOLDER ~/betacoin----------------------------------------------------------*/  
 strcpy(static_path , getenv("HOME"));
 strcat(static_path , "/betacoin");
 //Making ~/betacoin 
 if(mkdir(static_path , S_IRWXU) !=0)                //S_IRWXU - gives "read + write + execute" permission to current user.
 {
  if(errno != EEXIST)                    //mkdir throws non-zero number on failure. The errno is set to certain value. EEXIST means already exist.
  { 
   line();
   printf("\n\n\t\tCANNOT CREATE DIRECTORY %s.\n" , static_path);
   line();
   exit(1);
   }
  }
 printf("\n Created folder %s.." , static_path);



/*--MAKE FOLDER ~/betacoin/miner----------------------------------------------------------*/ 
  strcpy(tempname , static_path);
 strcat(tempname , "/miner");
 if(mkdir(tempname , S_IRWXU) !=0)
 {
  if(errno != EEXIST)
  {
   line();
   printf("\n\n\t\tCANNOT CREATE DIRECTORY %s.\n" , tempname);
   line();
   exit(1);
   }
  }
 printf("\n Created folder %s.." , tempname);



 
/*--MAKE FOLDER ~/betacoin/sha----------------------------------------------------------*/ 
 strcpy(tempname , static_path);
 strcat(tempname , "/sha");

 if(mkdir(tempname , S_IRWXU) !=0)
 {
  if(errno != EEXIST)
  {
   line();
   printf("\n\n\t\tCANNOT CREATE DIRECTORY %s.\n" , tempname);
   line();
   exit(1);
   }
  }
 printf("\n Created folder %s.." , tempname);



/*--MAKE FOLDER ~/betacoin/BLOCKCHAIN----------------------------------------------------------*/ 
 strcpy(tempname , static_path);
 strcat(tempname , "/BLOCKCHAIN");
 
 if(mkdir(tempname , S_IRWXU) !=0)
 {
  if(errno != EEXIST)
  {
   line();
   printf("\n\n\t\tCANNOT CREATE DIRECTORY %s.\n" , tempname);
   line();
   exit(1);
   }
  }
 printf("\n Created folder %s.." , tempname);



/*--MAKE FOLDER ~/betacoin/binary----------------------------------------------------------*/ 
 strcpy(tempname , static_path);
 strcat(tempname , "/binary");

 if(mkdir(tempname , S_IRWXU) !=0)
 {
  if(errno != EEXIST)
  {
   line();
   printf("\n\n\t\tCANNOT CREATE DIRECTORY %s.\n" , tempname);
   line();
   exit(1);
   }
  }
 printf("\n Created folder %s.." , tempname);


/*--MAKE FOLDER ~/betacoin/verify----------------------------------------------------------*/ 
 strcpy(tempname , static_path);
 strcat(tempname , "/verify");

 if(mkdir(tempname , S_IRWXU) !=0)
 {
  if(errno != EEXIST)
  {
   line();
   printf("\n\n\t\tCANNOT CREATE DIRECTORY %s.\n" , tempname);
   line();
   exit(1);
   }
  }
 printf("\n Created folder %s.." , tempname);



/*--MAKE FOLDER ~/betacoin/synchronize----------------------------------------------------------*/ 
 strcpy(tempname , static_path);
 strcat(tempname , "/synchronize");

 if(mkdir(tempname , S_IRWXU) !=0)
 {
  if(errno != EEXIST)
  {
   line();
   printf("\n\n\t\tCANNOT CREATE DIRECTORY %s.\n" , tempname);
   line();
   exit(1);
   }
  }
 printf("\n Created folder %s.." , tempname);


/*--COPY SHA FUNCTION----------------------------------------------------------*/ 
 strcpy(command , "cp ./SHA_function.py ~/betacoin/binary/SHA_function_DUP.py");
 printf("\n Running command: \n\t%s .." , command); 
    if(system(command) == 0)
     printf("\n Copied ./SHA_function.py to ~/betacoin/binary/SHA_function_DUP.py..");
    else
    {
     line();
     printf("\n\n\tERROR: Could not run %s..\n" , command);
     line();
     exit(1);
     }


/*--COPY MD5 FUNCTION----------------------------------------------------------*/
 strcpy(command , "cp ./MD5_function.py ~/betacoin/binary/MD5_function_DUP.py");
 printf("\n Running command: \n\t%s .." , command);             
    if(system(command) == 0)
     printf("\n Copied ./MD5_function.py to ~/betacoin/binary/MD5_function_DUP.py..");
    else
    {
     line();
     printf("\n\n\tERROR: Could not run %s..\n" , command);
     line();
     exit(1);
     }


/*--COPY NUMBER OF BLOCKS----------------------------------------------------------*/
 strcpy(command , "cp ./no_of_blocks.txt ~/betacoin/BLOCKCHAIN/no_of_blocks.txt");
 printf("\n Running command: \n\t%s .." , command);
    if(system(command) == 0)
     printf("\n Copied ./no_of_blocks.txt ~/betacoin/BLOCKCHAIN/no_of_blocks.txt..");
    else
    {
     line();
     printf("\n\n\tERROR: Could not run %s..\n" , command);
     line();
     exit(1);
     }



/*--COPY 0.block----------------------------------------------------------*/
 strcpy(command , "cp ./0.block ~/betacoin/BLOCKCHAIN/0.block");
 printf("\n Running command: \n\t%s .." , command);
    if(system(command) == 0)
     printf("\n Copied ./0.block to ~/betacoin/BLOCKCHAIN/0.block..");
    else
    {
     line();
     printf("\n\n\tERROR: Could not run %s..\n" , command);
     line();
     exit(1);
     }


/*--COPY BLOCK LIST----------------------------------------------------------*/
 strcpy(command , "cp ./block_list.txt ~/betacoin/BLOCKCHAIN/block_list.txt");
 printf("\n Running command: \n\t%s .." , command);
    if(system(command) == 0)
     printf("\n Copied ./block_list.txt to ~/betacoin/BLOCKCHAIN/block_list.txt..");
    else
    {
     line();
     printf("\n\n\tERROR: Could not run %s..\n" , command);
     line();
     exit(1);
     }


/*--SET DIFFICULTY TARGET----------------------------------------------------------*/ 
 strcpy(tempname , static_path);
 strcat(tempname , "/miner/difficulty_target.txt");
 fp = fopen(tempname , "w");
         if(fp == NULL)
         {
         line();
          printf("\n\n\tERROR: COULD NOT OPEN %s TO WRITE DIFFICULTY TARGET.\n" , tempname);
          line();
          exit(1);
          } 

 fprintf(fp , "%lu" , (unsigned long)2);
 fclose(fp);
 printf("\n Created file %s to set difficulty target.." , tempname);

/*--NUMBER OF MINERS IN NETWORK----------------------------------------------------------*/
 strcpy(tempname , static_path);
 strcat(tempname , "/miner/no_of_miners.txt");

 fp = fopen(tempname , "w");
         if(fp == NULL)
         {
         line();
          printf("\n\n\tERROR: COULD NOT OPEN %s TO WRITE NUMBER OF MINERS.\n" , tempname);
          line();
          exit(1);
          }

 fprintf(fp , "%hu" , (unsigned short)0);
 fclose(fp);
 printf("\n Created file %s to set difficulty target.." , tempname);




/*--COMPILE PROGRAM TO CREATE ACCOUNT----------------------------------------------------------*/
 strcpy(command , "gcc create_account.c -o ~/betacoin/binary/create_account");
 printf("\n Running command: \n\t%s .." , command);             
    if(system(command) == 0)
     printf("\n Compiled create_account.c..");
    else
    {
     line();
     printf("\n\n\tERROR: Could not run %s..\n" , command);
     line();
     exit(1);
     }


/*--COMPILE PROGRAM TO CREATE GENESIS BLOCK----------------------------------------------------------*/ 
 strcpy(command , "gcc create_genesis_block.c -o ~/betacoin/binary/create_genesis_block");
 printf("\n Running command: \n\t%s .." , command);
 if(system(command) == 0)
  printf("\n\tCompiled create_genesis_block.c..");
 else
  {
   line();
   printf("\n\n\tERROR: Could not run %s..\n" , command);
   line();
   exit(1);
   }


/*--COMPILE PROGRAM TO CREATE BLOCK----------------------------------------------------------*/ 
 strcpy(command , "gcc create_block.c -o ~/betacoin/binary/create_block");
  printf("\n Running command: \n\t%s.." , command);
 if(system(command) == 0)
  printf("\n\tCompiled create_block.c..");
 else
  {
   line();
   printf("\n\n\tERROR: Could not run %s..\n" , command);
   line();
   exit(1);
   }


/*--COMPILE PROGRAM TO CREATE LIST OF NEW BLOCKS----------------------------------------------------------*/ 
 strcpy(command , "gcc create_list_of_new_blocks.c -o ~/betacoin/binary/create_list_of_new_blocks");
  printf("\n Running command: \n\t%s .." , command);
 if(system(command) == 0)
  printf("\n\tCompiled create_list_of_new_blocks.c..");
 else
  {
   line();
   printf("\n\n\tERROR: Could not run %s ..\n" , command);
   line();
   exit(1);
   }


/*--COMPILE PROGRAM TO ADD A NEW MINER----------------------------------------------------------*/ 
 strcpy(command , "gcc miner_menu.c -o ~/betacoin/binary/miner_menu");
  printf("\n Running command: \n\t%s .." , command);
 if(system(command) == 0)
  printf("\n\tCompiled add_a_new_miner.c..");
 else
  {
   line();
   printf("\n\n\tERROR: Could not run %s ..\n" , command);
   line();
   exit(1);
   }


/*--COMPILE PROGRAM FIRST RUN----------------------------------------------------------*/ 
 strcpy(command , "gcc first_run.c -o ~/betacoin/binary/first_run");
 printf("\n Running command: \n\t%s .." , command);
 if(system(command) == 0)
  printf("\n\tCompiled first_run.c..");
 else
  {
   line();
   printf("\n\n\tERROR: Could not run %s ..\n" , command);
   line();
   exit(1);
   }


/*--COMPILE PROGRAM TO MAKE TRANSACTION----------------------------------------------------------*/
  strcpy(command , "gcc make_transaction.c -o  ~/betacoin/binary/make_transaction");
   printf("\n Running command: \n\t%s .." , command);
  if(system(command) == 0)
   printf("\n\tCompiled make_transaction.c ..");
  else
  {
   line();
   printf("\n\n\tERROR: Could not run %s ..\n" , command);
   line();
   exit(1);
   }

/*--COMPILE PROGRAM TO SEND NEW BLOCK----------------------------------------------------------*/
  strcpy(command , "gcc send_newblock.c -o  ~/betacoin/binary/send_newblock");
   printf("\n Running command: \n\t%s .." , command);
  if(system(command) == 0)
   printf("\n\tCompiled send_newblock.c ..");
  else
  {
   line();
   printf("\n\n\tERROR: Could not run %s ..\n" , command);
   line();
   exit(1);
   }


/*--COMPILE PROGRAM TO RECALCULATE BALANCE----------------------------------------------------------*/
  strcpy(command , "gcc recalculate_balance.c -o  ~/betacoin/binary/recalculate_balance");
   printf("\n Running command: \n\t%s .." , command);
  if(system(command) == 0)
   printf("\n\tCompiled recalculate_balance.c ..");
  else
  {
   line();
   printf("\n\n\tERROR: Could not run %s ..\n" , command);
   line();
   exit(1);
   }


/*--COMPILE PROGRAM TO MAKE TRANSACTION----------------------------------------------------------*/
  strcpy(command , "gcc synchronize.c -o  ~/betacoin/binary/synchronize");
   printf("\n Running command: \n\t%s .." , command);
  if(system(command) == 0)
   printf("\n\tCompiled synchronize.c ..");
  else
  {
   line();
   printf("\n\n\tERROR: Could not run %s ..\n" , command);
   line();
   exit(1);
   }


/*--COMPILE INDEX----------------------------------------------------------*/
  strcpy(command , "gcc index.c -o  ~/index");
   printf("\n Running command: \n\t%s .." , command);
  if(system(command) == 0)
   printf("\n\tCompiled index.c ..");
  else
  {
   line();
   printf("\n\n\tERROR: Could not run %s ..\n" , command);
   line();
   exit(1);
   }



/*------------------------------------------------------------*/ 

 #ifdef __linux__ 
  strcpy(command , "gcc merkle_tree.c -o  ~/betacoin/binary/merkle_tree -lm");
   printf("\n Running command: \n\t%s .." , command);
  if(system(command) == 0)
   printf("\n\tCompiled merkle_tree.c ..");
  else
  {
   line();
   printf("\n\n\tERROR: Could not run %s ..\n" , command);   
   line();
   exit(1);
   }


/*------------------------------------------------------------*/ 

  strcpy(command , "gcc verify_block.c -o  ~/betacoin/binary/verify_block -lm");
   printf("\n Running command: \n\t%s .." , command);
  if(system(command) == 0)
   printf("\n\tCompiled verify_transaction.c ..");
  else
  {
   line();
   printf("\n\n\tERROR: Could not run %s ..\n" , command);
   line();
   exit(1);
   }

/*------------------------------------------------------------*/ 



 #elif __APPLE__ 
  strcpy(command , "gcc merkle_tree.c -o  ~/betacoin/binary/merkle_tree");
   printf("\n Running command: \n\t%s .." , command);
  if(system(command) == 0)
   printf("\n\tCompiled merkle_tree.c ..");
  else
  {
   line();
   printf("\n\n\tERROR: Could not run %s ..\n" , command);
   line();
   exit(1);
   }


/*------------------------------------------------------------*/

  strcpy(command , "gcc verify_block.c -o  ~/betacoin/binary/verify_block");
   printf("\n Running command: \n\t%s .." , command);
  if(system(command) == 0)
   printf("\n\tCompiled verify_transaction.c ..");
  else
  {
   line();
   printf("\n\n\tERROR: Could not run %s ..\n" , command);
   line();
   exit(1);
   }

/*------------------------------------------------------------*/ 



  
 #endif


 printf("\n\n\n\tBUILD FINISHED.\n\t0 ERRORS\n"); 

 }
