#ifndef _GVERTEX_H_
#define _GVERTEX_H_

#include <list>
#include <string>
#include <vector>
#include <stdio.h>
#include "SPoint2.h"
#include "SPoint3.h"
#include "GEdge.h"

#ifndef GPointH
#include "GPoint.h"
#define GPointH 1
#endif

#include "GEntity.h"

#define MAX_LC 1.e22


class GVertex :public GEntity
{
protected:
	std::list<GEdge*> l_edges;
	double meshSize;

public:
	GVertex(GModel *m, int tag, double ms=MAX_LC);
	virtual ~GVertex();


	// get/set the coordinates of the vertex
	virtual GPoint point() const = 0;
	virtual double x() const = 0;
	virtual double y() const = 0;
	virtual double z() const = 0;
	virtual SPoint3 xyz() const { return SPoint3(x(), y(), z()); }
	virtual void setPosition(GPoint &p);



	// get/set the prescribed mesh size at the vertex
	inline double prescribedMeshSizeAtVertex() const { return meshSize; }
	virtual void setPrescribedMeshSizeAtVertex(double l) { meshSize = l; }


	// get the edges that this vertex bounds
	virtual std::list<GEdge*> edges() const{ return l_edges; }
	// add/delete an edge bounded by this vertex
	void addEdge(GEdge *e);
	void delEdge(GEdge *e);
};



#endif