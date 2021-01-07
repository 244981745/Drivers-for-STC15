#ifndef	_SPI_H
#define	_SPI_H

void			SpiPortInit		(unsigned char port);
unsigned char	SpiWriteCommand	(unsigned char INIT_COM);
void			SpiWriteData	(unsigned char INIT_DATA);


#endif