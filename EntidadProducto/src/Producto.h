/*
 * Producto.h
 *
 *  Created on: 11 may. 2021
 *      Author: Blanco Julian
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_


typedef struct{
	int idProducto;
	int idTipo;
	float precioUnidad;
}Producto;

int producto_setIdProducto();
int producto_getIdProducto();

int producto_setIdTipo();
int producto_getIdTipo();

float producto_setPrecioUnidad();
float producto_getPrecioUnidad();

#endif /* PRODUCTO_H_ */
