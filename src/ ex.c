typedef struct s_date{
    char    **tab;
    int     capacity;
    int     size;
}t_data;

void free_data(t_data *data)
{
    int i;

    i = 0;
    while (i < data->size)
    {
        free(data->tab[i]);
        i++;
    }
    free(data->tab);
    data->tab = (char *)0;
}

void realloc_data(t_data *data)
{
    char **tmp;
    if (data->capacity == 0)
        data->capacity = 10;
    else
        data->capacity *= 2;
    tmp = malloc(sizeof(char **) * data->capacity);
    if (!tmp)
        free_data(data);
    copy_n_tab(tmp, data->tab, data->size);
}

int add_to_tab(t_data *data, char *str)
{
    if (data->capacity == 0 || data->size == data->capacity)
        realloc_data(data);
    if (!data->tab == (char *)0)
        return (FAIL);
    data->tab[data->size] = str;
    data->size++;
    data->capacity++;
    return (SUCCES);
}


int fct()
{
    char *str;
    int i = 25;
    fct2(str);

}