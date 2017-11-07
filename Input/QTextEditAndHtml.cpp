#include <QtWidgets>
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QTextEdit* text = new QTextEdit;

    text->setHtml("<HTML>"
                  "<BODY BGCOLOR=MAGENTA>"
                  "<CENTER><IMG STC=\":/button/but.png\"><CENTER>"
                  "<H2><CENTER>GNOM POEM 3: MAGIC MAGIC</CENTER></H2>"
                  "<H3><CENTER>(http://ynstyn.tripod.com)</CENTER><H3>"
                  "<FONT COLOR=BLUE>"
                  "p ALIGN=\"center\">"
                  "<I>"
                  "Magic! Magic!<BR>"
                  "</I>"
                  "</P>"
                  "</FONT>"
                  "</BODY>"
                  "</HTML>"
                  );
    text->resize(320, 250);
    text->show();

    return app.exec();
}
