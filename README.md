# Introdução #

Este projeto implementa um gerador de labirintos perfeitos e um solucionador para esses labirintos utilizando a biblioteca customizada stb_image para gerar imagens mostrando o labirinto sendo construído/solucionado.

# Implementação #

Para realizar este projeto utilizamos a linguagem C++ e sua biblioteca padrão (STL), bem como a bibloteca stb_image para a criação de imagens. </br>

Também utilizamos uma estrutura de classes para realizar as funcionalidades do nosso projeto. Tais classes são: </br>

- Classe Maze:
Esta classe é responsável por guardar as informações do labirinto, como dimensões e estado das células. </br>

Ela também é responsável por construir o labirinto e possibilitar a modificação/consulta de suas celulas. </br>

- Classe Render:
Esta classe é responsável por estabelecer uma ligação entre o canvas e o maze para que com isso seja possível desenhar as etapas de criação/solução do maze. </br>

- Classe Canvas:
Esta classe é responsável por criar uma "tela" para possibilitar a pintura da imagem, utilizando funções para a criação de linhas verticais e horizontais e caixas utilizadas para representar o estado de uma célula. </br>

- Classe Solve:
Esta classe é responsável por resolver o labirinto utilizando recursão e chamar o render para desenhar a imagem a cada passo da resolução.</br>

# Compilação e execução #

Para executar o código, basta entrar na pasta raíz do projeto e digitar o comando **cmake -G "Unix Makefiles"**, opcionalmente, pode-se criar um diretório dentro da pasta raíz e apenas adicionar o caminho desta pasta raíz até o arquivo **CMakeLists.txt**. </br>

Após isso, basta digitar o comando **make** para compilar o projeto. </br>

Assim, com o projeto compilado, basta digitar **./Magos l c H W**, onde **l** é a quantidade de linhas do labirinto (altura), **c** é a quantidade de colunas do labirinto (largura), **H** é a altura das imagens e **W** a largura das imagens. </br>

Também é possível chamar **./Magos**, **./Magos l c** ou **./Magos l c H**. Respectivamente, estes comandos geram um labirinto 10x10 com imagens de 300x300 de tamanho, um labirinto com lxc dimensões com imagens de tamanho l.100xc.100 (cem vezes o tamanho de cada dimensão do labirinto) e um labirinto com dimensões lxc com imagens de tamanho HxH. </br>

# Autoria #

Todos os códigos aqui implementados foram desenvolvidos por [Kevin Wallacy de Souza Maciel](https://github.com/kevinwall) (Email de contato: <kevinwall@ufrn.edu.br>) e [Giovanne da Silva Santos](https://github.com/GSDante) (Email de contato: <giovannedssantos@gmail.com>) 

&copy; IMD/UFRN 2018-2019
