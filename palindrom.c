# include <stdio.h>
# include <string.h>

int main( )
{


	FILE *filePointer ;


	char dataToBeRead[200];


	filePointer = fopen("new.txt", "r");  //file name is new.txt. Also, paths of this program and new.txt are same

	if ( filePointer == NULL )
	{
		printf( "new.txt file failed to open." );
	}
	else
	{

		printf("The file is opened\n") ;

		while( fgets ( dataToBeRead, 200, filePointer ) != NULL )
		{

			// Print the dataToBeRead
			//printf( "Read Data : %s\n\n" , dataToBeRead ) ;
                int i,j,k,l,len,count = 0;

              len = strlen(dataToBeRead);
                int temp;
              for(i=0;i<len;i++)
              {
                  temp=count;
                if(dataToBeRead[i] != ' ' || dataToBeRead[i] != '\n')
                {
                  for(j=i;j<len;j++)
                  {
                      if(dataToBeRead[j] == ' ' || dataToBeRead[j] == '\n')
                        break;
                  }
                }

                for(k=i,l=j-1;;)
                {
                  if(dataToBeRead[k] != dataToBeRead[l])
                    break;
                  else if(k >= l)
                  {
                    count = count + 1;

                    break;
                  }
                  else
                  {
                    k = k + 1;
                    l = l - 1;
                    continue;
                  }
                }
                if(temp!=count)
                {
                    for(int p=i;p<j;p++)
                    {
                        printf("%c",dataToBeRead[p]);
                    }
                }
                printf(" ");
                i = j;
              }


		}


		// Closing the file using fclose()
		fclose(filePointer) ;

	}
	return 0;
}
