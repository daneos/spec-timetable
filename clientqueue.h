/* clientqueue.h -- timetable distribution, client queue class header
 * Copyright (C) 2013 daneos
 * See LICENSE for legal information
 */

#if !defined(__CLIENTQUEUE_H__)
#	define __CLIENTQUEUE_H__
//-----------------------------------------------------------------------------
#include "include/tsocket.h"
//-----------------------------------------------------------------------------

class Client
{
protected:
	int id;
	tsocket *sock;

public:
	Client(const char *ip, const char *port);
	~Client();
	tsocket *getSocket();
	int getID(void);
};
//-----------------------------------------------------------------------------

class Queue
{
protected:
	int index;
	Client **list;

public:
	Queue();
	~Queue();
	int addClient(const char *ip, const char *port);
	void removeClient(int id);
	Client **getList(void);
};

#endif /*__CLIENTQUEUE_H__ */