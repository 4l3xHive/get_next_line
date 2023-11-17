<!--HEADER-->
<h1 align="center"> Get_next_line | 
  <picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://cdn.simpleicons.org/42/white">
  <img alt="42" width=40 align="center" src="https://cdn.simpleicons.org/42/Black">
 </picture>
 Cursus 
  <img alt="Complete" src="https://raw.githubusercontent.com/Mqxx/GitHub-Markdown/main/blockquotes/badge/dark-theme/complete.svg">
</h1>
<!--FINISH HEADER-->

> This project is about programming a function that returns a line read from a file descriptor.

<img align="right" width="150" src="https://github.com/josephcheel/readme/blob/main/resources/125_Success.png">

### What is the the project about
Get_next_line function reads from a file descriptor and returns the first line encountered, in other words when encountering a line break character <code>\n</code>. The function uses **static variables** to "remember" the last line ret and continue from that point. 

> <picture>
>   <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/Mqxx/GitHub-Markdown/main/blockquotes/badge/light-theme/info.svg">
>   <img alt="Info" src="https://raw.githubusercontent.com/Mqxx/GitHub-Markdown/main/blockquotes/badge/dark-theme/info.svg">
> </picture><br>
>
> When compiling you should compile with <code>-D BUFFER_SIZE=nbr</code>. Where nbr is the numbers of bytes that read function read each time.

## Mandatory Instrucctions
* The Allowed functions are: <code>read, malloc, free</code>
* Files nedded: <kbd>get_next_line.c</kbd><kbd>get_next_line_utils.c</kbd><kbd>get_next_line.h</kbd>
* Prototype of the function: <code>char *get_next_line(int fd);</code>. Where <code>fd</code> is the file descriptor to read from.
## Bonus Instrucctions

#### To compile the project
```shell
> gcc -Wall -Wextra -Werror -D BUFFER_SIZE=Nbr <files> main.c
> gcc -Wall -Wextra -Werror -D BUFFER_SIZE=Nbr <files_bonus> main.c 
```
> <picture>
>   <source media="(prefers-color-scheme: light)" srcset="https://raw.githubusercontent.com/Mqxx/GitHub-Markdown/main/blockquotes/badge/light-theme/info.svg">
>   <img alt="Info" src="https://raw.githubusercontent.com/Mqxx/GitHub-Markdown/main/blockquotes/badge/dark-theme/info.svg">
> </picture><br>
>
> Nbr is the numbers of bytes that read function read each time. 
