    /* TAD */
struct veiculo {
    char placa[8];
    char marca[25];
    char modelo[30];
    char cor[25];
    int hora[2];
};

typedef struct veiculo Veiculo;

Veiculo* vei_cria();
int vei_insere(char placa[7], char marca[25], char modelo[30], char cor[25], Veiculo * vei);
void vei_libera(Veiculo* vei);
void vei_imprimi(Veiculo vei);

void horaAtual(int *Hora);

    /* Lista */
typedef struct lista *Lista;
typedef struct lista Node;

Lista* lista_cria(float priHora, float restHora);
int lista_insere(Lista *li, Veiculo vei);
int lista_imprimi(Lista *li);
int lista_consulta(Lista *li, char *placa);
int lista_retira(Lista *li, char *placa);
