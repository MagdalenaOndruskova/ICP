#ifndef MYCOORDINATE_H
#define MYCOORDINATE_H
/**
 * @brief The MyCoordinate class
 * @file mycoordinate.h
 * @author Magdalena Ondruskova
 *
 * This class represents coordinates in the public transport map
 *  whith is used to work with streets, stops, vehicles etc.
 */
#include <QPointF>

class MyCoordinate : public QPointF
{
public:
    /**
     * @brief MyCoordinate Constructor for class MyCoordinate
     */
    MyCoordinate();

    /**
     * @brief diffX Function counts difference between two X coordinates (this.x - c.x)
     * @param coor Second coordinate
     * @return difference between two X coordinates
     */
    double diffX(MyCoordinate coor);

    /**
     * @brief diffY Function counts difference between two Y coordinates (this.y - c.y)
     * @param coor Second coordinate
     * @return difference between two Y coordinates
     */
    double diffY(MyCoordinate coor);

    /**
     * @brief countVector Function counts the size of vector between two points
     * @param start point1
     * @param end point2
     * @return size of vector
     */
    double countVector(MyCoordinate start, MyCoordinate end);
};

#endif // MYCOORDINATE_H
