#include <QApplication>
#include <QtGui>
#include <QTimer>
#include <iostream>
#include <QString>


class TestApp: public QApplication {
       public:
    TestApp(int &argc, char **argv);
    public slots:
    void timeout();
};

class Tidget : public QMainWindow
{
    
public:
    Tidget(QWidget *parent=0);
    void mousePressEvent(QMouseEvent *);	// event
    void mouseMoveEvent(QMouseEvent *);		// event
    void mouseReleaseEvent(QMouseEvent *);	// event
    void setName(QPoint x){
			end = x;
		}
	 QPoint getName(){
		return end;
	}

  
    QRubberBand *rubberBand;  
    QPoint origin;
    QPoint end;
    int x1;
    int y1;
    int x2;
    int y2;
    int w;
    int h;
private:

    

};

Tidget::Tidget(QWidget *parent)
	: QMainWindow(parent)
{
   	
    QWidget *mainWidget = new QWidget;
    mainWidget->setBackgroundRole(QPalette::Light);
    mainWidget->setAutoFillBackground(true);
    setCentralWidget(mainWidget);
    setStyleSheet("background:transparent;");
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
    
	setWindowState(Qt::WindowFullScreen);
   
    rubberBand = NULL;
}
void Tidget::mousePressEvent(QMouseEvent *event)
 {
     origin = event->pos();
     if (!rubberBand)
         rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
     rubberBand->setGeometry(QRect(origin, QSize()));
     rubberBand->show();

     x1=event->x();
     y1=event->y();

 }

 void Tidget::mouseMoveEvent(QMouseEvent *event)
 {
     rubberBand->setGeometry(QRect(origin, event->pos()).normalized());
	
 }

void Tidget::mouseReleaseEvent(QMouseEvent *event)
 {
	 end = event->pos();
	x2=event->x();
        y2=event->y();
     rubberBand->hide();
	 

 std::cout <<std::abs(x2-x1)<<"x"<<std::abs(y2-y1)<<"+"<<x1<<"+"<<y1<<std::endl;

	QCoreApplication::exit(0); 

 }

 
 
 void myMessageOutput(QtMsgType type, const char *msg)
{
	//qDebug()<<QMouseEvent;
	
    //do nothing, i.e. discard message completely
}




     
 int main(int argc, char * argv[])
{
    QApplication app(argc,argv);
     qInstallMsgHandler(myMessageOutput);
    
	 
    Tidget rubber;

    rubber.show();

	
    return app.exec();
	
}
