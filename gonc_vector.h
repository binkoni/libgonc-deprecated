struct gonc_vector
{
    void* array[];
    size_t size;
    size_t data_size;
}

struct gonc_vector* gonc_vector_create(size_t size);

int gonc_vector_set(struct gonc_vector* vector, size_t index, void* data);

int gonc_vector_add(struct gonc_vector* vector, size_t index, void* data);

int gonc_vector_get(struct gonc_vector* vector, size_t index, void* data);

int gonc_vector_remove(struct gonc_vector* vector, size_t index, void* data);

int gonc_vector_destroy(struct gonc_vector* vector);
