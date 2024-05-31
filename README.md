# cryptography-postquantum
Universidad Nacional Autonoma de Mexico.

Facultad de Ingeniera.

Project 02: POST-QUANTUM CRYPTOGRAPHY PROJECT

Criptografa.

Nombre de los integrantes:
 - Alcantara Guerrero Alfredo Guadalupe.
 - Martnez Jimenez Mara Fernanda.
 - Martnez Manzo Adrian.
 - Maya Segundo Marisol.
 - Peralta Perez Saul.

Fecha de entrega: 30/05/2024

Grupo: 02

Nombre de la profesora: Roco Alejandra Aldeco Perez.

Semestre: 2024-2

## Ejecución del código
### Pre-requisitos

Para ejecutar los ejemplos, se requiere la instalación previa de la biblioteca liboqs en el sistema. Para ello, se recomienda seguir el paso a paso de la [documentación oficial](https://github.com/open-quantum-safe/liboqs?tab=readme-ov-file#linux-and-mac) de esta biblioteca.

### Compilación

Después de haber instalado la biblioteca, se requiere de la compilación de los códigos para su ejecución. En nuestro caso, se realizó con GCC en Linux utilizando el siguiente comando.

```
gcc -Ibuild/include/ -Lbuild/lib/ -Wl,-rpath=build/lib <codigo>.c -o <codigo> -loqs -lcrypto
```
### Ejecución

Por último, se ejecuta cada uno de los códigos para probar cada algoritmo.

```
./<codigo>
```
