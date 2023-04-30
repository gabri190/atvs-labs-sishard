#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void modifica_string (char *url, char *res){
    int i, local_ultimo_ponto;
    int res_cont = 0;
    int inicial = 0;
    // res=malloc(sizeof(char)*500);
    for(i = 2; url[i] != '\0' ; i++){
        if(url[i-2]=='/' && url[i-1]=='/'){
            inicial=i;
            break;
        }
    }
   
    for(i = inicial; url[i]!='\0'; i++){
        printf("url[i] = %c\n", url[i]);
        if(url[i]=='/' || url[i]=='.'){
            if (url[i]=='.') {
                local_ultimo_ponto = res_cont;
            }
            res[res_cont]='_';
            res_cont++;
        } else {
            res[res_cont]=url[i];
            res_cont++;
        }
        
    }
    res[local_ultimo_ponto] = '.';
}

 
static size_t write_data(void *ptr, size_t size, size_t nmemb, char *filename)
{
    size_t written = 0;
    char buf[1];

    int fd = open(filename, O_RDWR | O_CREAT, 0700);

    while (written < nmemb) {
        while (read(fd, buf, 1) != 0) {
        }
        write(fd, (char *)&ptr[written], 1);
        written++;
    }
    close(fd);
    return written;
}

void download_url(char *url, char *url_filename) {
    CURL *curl_handle;

    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* set URL to get here */
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);

    /* Switch on full protocol/debug output while testing */
    curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);

    /* disable progress meter, set to 0L to enable it */
    curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

    /* send all data to this function  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

    /* write the page body to this file handle */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, url_filename);

    /* get it! */
    curl_easy_perform(curl_handle);

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);

    curl_global_cleanup();
}


int main(int argc, char *argv[]){
    char nome_url[100];
    printf("url recebida = %s\n", argv[1]);
    modifica_string(argv[1], nome_url);
    // printf(" string aqui %s\n",str);
    printf("nome do arquivo url = %s\n", nome_url);
    
    download_url(argv[1], nome_url);
    return 0;
}

   

   

