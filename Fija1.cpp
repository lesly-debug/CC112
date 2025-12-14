#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

const int MAX_UNIQUE=100;

struct CountItem {
    string id;
    int count;
};

struct StatsUsuario{
    int total_eventos=0;
    int login_ok=0;
    int login_fail=0;
    bool intrusion=false;

    CountItem* accesos_por_dia=nullptr;
    int num_dias=0;
    CountItem* ips_frecuentes=nullptr;
    int num_ips=0;

    string dia_mas_activo="N/A";
    string ip_mas_usada="N/A";
    
    int fallos_consecutivos=0;
    string fecha_actual="";
};

int buscarItem(CountItem* items, int size, const string& id) {
    for (int i=0;i<size;++i) {
        if (items[i].id==id) {
            return i;
        }
    }
    return -1;
}

void incrementarItem(CountItem*& items, int& size, const string& id) {
    int index=buscarItem(items,size,id);
    if (index!=-1) {
        items[index].count++;
    }else{
        if (size>=MAX_UNIQUE) {
             cerr<<"Advertencia: Limite de "<<MAX_UNIQUE<<" items alcanzado."<< endl;
             return;
        }
        
        CountItem* new_items=new CountItem[size+1];
        for (int i=0;i<size;++i) {
            new_items[i]=items[i];
        }

        if(items!=nullptr) {
            delete[] items;
        }
        items=new_items;
        
        items[size].id=id;
        items[size].count=1;
        size++;
    }
}

void liberarStats(StatsUsuario* usuarios, int num_usuarios) {
    if (usuarios) {
        for (int i=0;i<num_usuarios;++i) {
            delete[] usuarios[i].accesos_por_dia;
            delete[] usuarios[i].ips_frecuentes;
        }
        delete[] usuarios;
    }
}

void procesarLogs() {
    const string ARCHIVO_ENTRADA="accesos.log";
    const string ARCHIVO_SALIDA="reporte_usuarios.txt";
    
    string* nombres_usuarios=nullptr;
    StatsUsuario* stats_usuarios=nullptr;
    int num_usuarios=0;

    ifstream archivo_in(ARCHIVO_ENTRADA);

    if (!archivo_in.is_open()) {
        cerr<<"Error: No se pudo abrir el archivo de log '" << ARCHIVO_ENTRADA << "'. Asegúrese de que existe." << endl;
        return;
    }

    string linea;
    while(getline(archivo_in, linea)) {
        stringstream ss(linea);
        string segmento;
        string partes[4]; 
        int p_index = 0;

        while(getline(ss,segmento,';')&&p_index < 4) {
            partes[p_index++]=segmento;
        }

        if(p_index != 4)continue; 

        string usuario=partes[0];
        string fecha_hora=partes[1];
        string ip=partes[2];
        string evento=partes[3];
        string fecha=fecha_hora.substr(0,10); 

        int user_index=buscarItem(reinterpret_cast<CountItem*>(nombres_usuarios),num_usuarios, usuario);

        if(user_index == -1){
            string* new_nombres=new string[num_usuarios+1];
            for(int i=0;i<num_usuarios;++i) new_nombres[i]=nombres_usuarios[i];
            if(nombres_usuarios != nullptr) delete[] nombres_usuarios;
            nombres_usuarios=new_nombres;
            nombres_usuarios[num_usuarios]=usuario;

            StatsUsuario* new_stats=new StatsUsuario[num_usuarios + 1];
            for (int i=0;i<num_usuarios;++i) new_stats[i] = stats_usuarios[i];
            if (stats_usuarios!=nullptr) liberarStats(stats_usuarios,num_usuarios); 
            stats_usuarios=new_stats;
            user_index=num_usuarios;
            num_usuarios++;
        }

        StatsUsuario& stats=stats_usuarios[user_index];
        stats.total_eventos++;
        
        incrementarItem(stats.ips_frecuentes, stats.num_ips, ip);
        incrementarItem(stats.accesos_por_dia, stats.num_dias, fecha);

        if(evento=="LOGIN_OK") {
            stats.login_ok++;
            stats.fallos_consecutivos = 0; 
        }else if(evento=="LOGIN_FAIL") {
            stats.login_fail++;
            if (stats.fecha_actual==fecha) {
                stats.fallos_consecutivos++;
            } else {
                stats.fallos_consecutivos=1; 
                stats.fecha_actual=fecha;
            }

            if (stats.fallos_consecutivos>=3) {
                stats.intrusion=true;
            }
        }
    }

    for (int i=0;i<num_usuarios;++i) {
        StatsUsuario& stats=stats_usuarios[i];

        int max_accesos=0;
        for (int d=0;d<stats.num_dias;++d) {
            if(stats.accesos_por_dia[d].count>max_accesos) {
                max_accesos=stats.accesos_por_dia[d].count;
                stats.dia_mas_activo=stats.accesos_por_dia[d].id;
            }
        }

        int max_ip_count=0;
        for (int p=0;p<stats.num_ips;++p) {
            if(stats.ips_frecuentes[p].count>max_ip_count) {
                max_ip_count=stats.ips_frecuentes[p].count;
                stats.ip_mas_usada=stats.ips_frecuentes[p].id;
            }
        }
    }

    for (int i=0;i<num_usuarios;++i) {
        for (int j=i+1;j<num_usuarios;++j) {
            if (stats_usuarios[i].total_eventos<stats_usuarios[j].total_eventos) {
                StatsUsuario temp_stats=stats_usuarios[i];
                stats_usuarios[i]=stats_usuarios[j];
                stats_usuarios[j]=temp_stats;

                string temp_nombre=nombres_usuarios[i];
                nombres_usuarios[i]=nombres_usuarios[j];
                nombres_usuarios[j]=temp_nombre;
            }
        }
    }

    ofstream archivo_out(ARCHIVO_SALIDA);
    if (!archivo_out.is_open()) {
        cerr<<"Error: No se pudo crear el archivo de salida '" << ARCHIVO_SALIDA << "'." << endl;
        liberarStats(stats_usuarios, num_usuarios);
        delete[] nombres_usuarios;
        return;
    }

    for (int i=0; i<num_usuarios;++i) {
        const StatsUsuario& stats=stats_usuarios[i];

        archivo_out<<"USUARIO: " <<nombres_usuarios[i]<<"\n";
        archivo_out<<"Eventos totales: "<<stats.total_eventos<< "\n";
        archivo_out<<"Login exitosos: "<<stats.login_ok<<"\n";
        archivo_out<<"Login fallidos: "<<stats.login_fail<<"\n";
        archivo_out<<"Dia mas activo: "<<stats.dia_mas_activo<<"\n";
        archivo_out<<"IP mas usada: "<<stats.ip_mas_usada<<"\n";
        archivo_out<<"Intrusion detectada: "<<(stats.intrusion ? "SI" : "NO")<<"\n";
    }

    cout<<"Reporte generado con éxito en '"<<ARCHIVO_SALIDA <<"'"<<endl;
    
    liberarStats(stats_usuarios,num_usuarios);
    delete[] nombres_usuarios;
}