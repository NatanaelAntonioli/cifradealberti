#include <iostream>

using namespace std;



class cifra {

private:

    string disco_FORA;
    string disco_DENTRO;

    string cifra_DENTRO;

    char indice;
    int incremento;
    int periodo;

public:

    cifra(){

        disco_FORA = "ABCDEFGILMNOPQRSTVXZ1234";
        disco_DENTRO = "mqihfdbacegklnprtuz&xyso";

    }

    void realocar(char input_indice){

        int valor_indice;
        bool nao_ta_no_disco = false;

        for (int i =0; i < 24; i++){

            if (input_indice == disco_DENTRO[i]){

                valor_indice = i;
                nao_ta_no_disco = false;
                i = 25;

            }

            else {

                nao_ta_no_disco = true;
            }

        }

        if (nao_ta_no_disco == true){

            return;

        }

        else {

            indice = input_indice;
        }

        for (int i = 0; i < 24 - valor_indice; i++){

            cifra_DENTRO[i] = disco_DENTRO[i + valor_indice];

        }

        int contador = 0;
        for (int i = 24 - valor_indice; i < 24; i++ ){

            cifra_DENTRO[i] = disco_DENTRO[contador];
            contador++;

        }
    }


    void print_cifra(){ /// Essa função imprime os discos na tela

        cout << "--------------------------------------------------------" << endl;

        for (int i = 0; i < 24; i++){

            cout << disco_FORA[i] << " ";

        }
        cout << endl;

        for (int i = 0; i < 24; i++){

            cout << cifra_DENTRO[i] << " ";

        }
        cout << endl;

        cout << "--------------------------------------------------------" << endl;


    };


    int retornar_indice_numerico (char caractere, string texto){

        for (int t = 0; t < texto.size(); t++){


        if (caractere == texto[t] || toupper(caractere) == texto[t] || tolower(caractere) == texto[t]){

            return t;

        }

        else{

            //cout << caractere << "nao e igual a" << texto[i];

        }

    }

    return 99;




    }

    bool caractere_esta_na_string (char caractere, string texto){


        for (int i = 0; i < texto.size(); i++){


            if (caractere == texto[i] || toupper(caractere) == texto[i] || tolower(caractere) == texto[i]){

                return true;

            }

        }


        return false;

}

    char criptografar_modo_numerico(char limpo){

        /// 1) verificar se o caractere está no disco superior

        if (caractere_esta_na_string(limpo, disco_FORA)){

            /// 2a) se sim, criptografar

            int index;

            index = retornar_indice_numerico(limpo, disco_FORA);

            char resultado;
            resultado = cifra_DENTRO[index];

            /// 3) verificar se é um número

                if (limpo == '1' || limpo == '2' || limpo == '3' || limpo == '4'){


                    /// 4) achar o caractere em baixo do dígito

                    char caractere;
                    caractere = resultado;

                    /// 5) realocar a cifra
                    realocar(caractere);

                }

             /// 6) Retornar o caractere criptografado

            return resultado;

        }

        else{

            /// 2b) se não, deixar o caractere como esta

            return toupper(limpo);

        }

    };

    char descriptografar_modo_numerico(char cifrado){

        if (isspace(cifrado) != 0 || cifrado == '.' || cifrado == ','){

            return ' ';

        }


        if (isupper(cifrado) == 0 ){

        /// 1) encontrar o indice do caractere

        int index;
        int var;

        for (int q = 0; q < 24; q++){

            if (cifrado == cifra_DENTRO[q]){

                index = q;

            }


        }


        /// 2a) se sim, decifrar


            char resultado;
            resultado = disco_FORA[index];

            /// 3) verificar se é um número

                if (resultado == '1' || resultado == '2' || resultado == '3' || resultado == '4'){

                    /// 5) realocar a cifra
                    realocar(cifrado);

                }


             /// 6) Retornar o caractere criptografado

            return resultado;

        }

        else {

            return cifrado;
        }
    }

    char criptografar_modo_alfabetico(char limpo){

        /// 1) verificar se o caractere está no disco superior

        if (isspace(limpo) != 0){

            return ' ';

        }

        if (caractere_esta_na_string(limpo, disco_FORA)){

            /// 2a) se sim, criptografar

            int index;

            index = retornar_indice_numerico(limpo, disco_FORA);

            char resultado;
            resultado = cifra_DENTRO[index];

            /// 3) verificar se é letra maiuscula

                if (isupper(limpo) != 0){

                    ///cout << "a letra " << limpo << " e maiuscula" << endl;

                    /// 4) achar o caractere em baixo do dígito

                    char caractere;
                    caractere = resultado;
                    resultado = toupper(resultado);

                    /// 5) realocar a cifra
                    realocar(tolower(limpo));

                }

             /// 6) Retornar o caractere criptografado

            return resultado;

        }

        else{

            /// 2b) se não, deixar o caractere como esta

            return '#';

        }

    };

    char descriptografar_modo_alfabetico(char cifrado){

      if (isspace(cifrado) != 0 || cifrado == '.' || cifrado == ',' || cifrado == '#'){

            return ' ';

        }

        //(sempre vai ser no nosso caso)

        /// 1) encontrar o indice do caractere

        int index;
        int var;

        for (int q = 0; q < 24; q++){

            if (cifrado == cifra_DENTRO[q] || tolower(cifrado) == cifra_DENTRO[q]){

                index = q;

            }


        }


        /// 2a) se sim, decifrar


            char resultado;
            resultado = disco_FORA[index];

            /// 3) verificar se é letra maiuscula

                if (isupper(cifrado)){

                    //cout << "ALOCANDO" << endl;
                    /// 5) realocar a cifra
                    realocar(tolower(resultado));

                }


             /// 6) Retornar o caractere criptografado

            return resultado;

    }

};

bool esta_na_string (char letra, string texto){

    for (int e = 0; e < texto.size(); e++){

        if (letra == texto[e]){

            return true;

        }

    }

    return false;

}

int main()
{

    /// Variáveis do menu

    int menu1;
    int menu2;
    bool indice_ok = false;
    bool continuar = true;

    /// Variaveis auxiliares para consulta

    string aux_disco_FORA = "ABCDEFGILMNOPQRSTVXZ1234";
    string aux_disco_DENTRO = "mqihfdbacegklnprtuz&xyso";

    /// Variaveis de input e output

    char indice;
    string mensagem;
    char para_imprimir;

    /// Objeto da cifra

    cifra alberti;

    /// Codigo principal

    while (continuar == true){


    cout << "   ____ _  __                 _           _    _ _               _   _ " << endl;
    cout << "  / ___(_)/ _|_ __ __ _    __| | ___     / \\  | | |__   ___ _ __| |_(_)" << endl;
    cout << " | |   | | |_| '__/ _` |  / _` |/ _ \\   / _ \\ | | '_ \\ / _ \\ '__| __| |" << endl;
    cout << " | |___| |  _| | | (_| | | (_| |  __/  / ___ \\| | |_) |  __/ |  | |_| |" << endl;
    cout << "  \\____|_|_| |_|  \\__,_|  \\__,_|\\___| /_/   \\_\\_|_.__/ \\___|_|   \\__|_|" << endl;
    
    cout << endl;
    cout << "O presente programa  e uma ferramenta para criptografia na Cifra de Alberti conforme " << endl;
    cout << "os dois metodos descritos por Leon Battista Alberti em 1467. Para se adatar ao alfabeto" << endl;
    cout << "de 26 letras e permitir o ataque por forca bruta, algumas modificacoes foram feitas." << endl;
    cout << endl;
    cout << "Desenvolvido por Natanael Antonioli/Fabrica de Noobs em fevereiro de 2019" << endl;
    cout << endl;


    cout << endl;
    cout << "1 - Metodo numerico (numeros indicam uma mudanca no indice)" << endl;
    cout << "2 - Metodo alfabetico (letras maiusculas indicam uma mudanca no indice)" << endl;
    cout << "3 - Metodo periodico (a mudanca ocorre com base em nuneros fixos)" << endl;
    cout << endl;
    cout << "O que deseja fazer? ";
    cin >> menu1;
    cin.ignore();
    cout << endl;

    if (menu1 == 1){

        cout << "1 - Criptografar com um indice" << endl;
        cout << "2 - Descriptografar com um indice" << endl;
        cout << "3 - Descriprtografar tentando todos os indices possiveis (cifras impossiveis poderao apresentar resultados distorcidos)" << endl;
        cout << endl;
        cout << "O que deseja fazer? ";
        cin >> menu2;
        cin.ignore();
        cout << endl;

        if (menu2 == 1){

            while (indice_ok == false){

                cout << "Insira o indice: ";
                cin >> indice;
                cin.ignore();

                if (esta_na_string(indice, aux_disco_DENTRO)){

                    indice_ok = true;

                }

                else {
                    cout << "O indice inserido nao e valido, pois nao pertence ao disco interior." << endl;
                }

            } indice_ok = false;


            cout << endl;

            alberti.realocar(indice);
            cout << "A cifra com o indice inicial e:" << endl;
            alberti.print_cifra();

            cout << endl;

            cout << "Insira a mensagem:";
            getline(cin, mensagem);
            cout << endl;
            cout << "A mensagem criptografada e:" << endl;
            cout << endl;

            for (int i = 0; i < mensagem.size(); i++){

                para_imprimir = alberti.criptografar_modo_numerico(mensagem[i]);

                cout << para_imprimir;

            }

            cout << endl;

        } /// menu1 = 1 e menu2 = 1

        if (menu2 == 2){

            while (indice_ok == false){

                cout << "Insira o indice: ";
                cin >> indice;
                cin.ignore();

                if (esta_na_string(indice, aux_disco_DENTRO)){

                    indice_ok = true;

                }

                else {
                    cout << "O indice inserido nao e valido, pois nao pertence ao disco interior." << endl;
                }

            } indice_ok = false;

            cout << endl;

            alberti.realocar(indice);
            cout << "A cifra com o indice inicial e:" << endl;
            alberti.print_cifra();

            cout << endl;

            cout << "Insira a mensagem:";
            getline(cin, mensagem);
            cout << endl;
            cout << "A mensagem descriptografada e:" << endl;
            cout << endl;

            for (int i = 0; i < mensagem.size(); i++){

                para_imprimir = alberti.descriptografar_modo_numerico(mensagem[i]);

                cout << para_imprimir;

            }

            cout << endl;

        } /// menu1 = 1 e menu2 = 2

        if (menu2 == 3){

            cout << "Insira a mensagem. Letras nao permitidas nao serao critptografadas e ficaram em caixa alta.";
            getline(cin, mensagem);
            cout << endl;

            for (int i = 0; i < 24; i++){


                indice = aux_disco_DENTRO[i];

                alberti.realocar(indice);

                cout << "-------------------- Com o indice " << indice << "----------------" << endl;

                for (int j = 0; j < mensagem.size(); j++){

                    para_imprimir = alberti.descriptografar_modo_numerico(mensagem[j]);

                    cout << para_imprimir;

                }
                cout << endl;

            }

        } /// menu1 = 1 e menu2 = 3

    } /// menu1 = 1

    if (menu1 == 2){

        cout << "1 - Criptografar com um indice" << endl;
        cout << "2 - Descriptografar com um indice" << endl;
        cout << "3 - Descriprtografar tentando todos os indices possiveis (cifras impossiveis poderao apresentar resultados distorcidos)" << endl;
        cout << endl;
        cout << "O que deseja fazer? ";
        cin >> menu2;
        cin.ignore();
        cout << endl;

        if (menu2 == 1 ){

            while (indice_ok == false){

                cout << "Insira o indice: ";
                cin >> indice;
                cin.ignore();

                if (esta_na_string(indice, aux_disco_DENTRO)){

                    indice_ok = true;

                }

                else {
                    cout << "O indice inserido nao e valido, pois nao pertence ao disco interior." << endl;
                }

            } indice_ok = false;


            cout << endl;

            alberti.realocar(indice);
            cout << "A cifra com o indice inicial e:" << endl;
            alberti.print_cifra();

            cout << endl;

            cout << "Insira a mensagem. Letras nao permitidas serao substituidas por #:";
            getline(cin, mensagem);
            cout << endl;
            cout << "A mensagem criptografada e:" << endl;
            cout << endl;

            for (int i = 0; i < mensagem.size(); i++){

                para_imprimir = alberti.criptografar_modo_alfabetico(mensagem[i]);

                cout << para_imprimir;

            }

            cout << endl;


        } /// menu1 = 2 e menu2 = 1

        if (menu2 == 2 ){

            while (indice_ok == false){

                cout << "Insira o indice: ";
                cin >> indice;
                cin.ignore();

                if (esta_na_string(indice, aux_disco_DENTRO)){

                    indice_ok = true;

                }

                else {
                    cout << "O indice inserido nao e valido, pois nao pertence ao disco interior." << endl;
                }

            } indice_ok = false;


            cout << endl;

            alberti.realocar(indice);
            cout << "A cifra com o indice inicial e:" << endl;
            alberti.print_cifra();

            cout << endl;

            cout << "Insira a mensagem. Letras nao permitidas serao substituidas por #:";
            getline(cin, mensagem);
            cout << endl;
            cout << "A mensagem criptografada e:" << endl;
            cout << endl;

            for (int i = 0; i < mensagem.size(); i++){

                para_imprimir = alberti.descriptografar_modo_alfabetico(mensagem[i]);

                cout << para_imprimir;

            }

            cout << endl;


        } /// menu1 = 2 e menu2 = 2

    if (menu2 == 3){

            cout << "Insira a mensagem:";
            getline(cin, mensagem);
            cout << endl;

            for (int i = 0; i < 24; i++){


                indice = aux_disco_DENTRO[i];

                alberti.realocar(indice);

                cout << "-------------------- Com o indice " << indice << "----------------" << endl;

                for (int j = 0; j < mensagem.size(); j++){

                    para_imprimir = alberti.descriptografar_modo_alfabetico(mensagem[j]);

                    cout << para_imprimir;

                }
                cout << endl;

            }

        } /// menu1 = 2 e menu2 = 3

    } /// menu1 = 2

    }
}
