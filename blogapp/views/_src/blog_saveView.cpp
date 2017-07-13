#include <QtCore>
#include <TreeFrogView>
#include "blog.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_saveView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  blog_saveView() : TActionView() { }
  QString toString();
};

QString blog_saveView::toString()
{
  responsebody.reserve(1697);
  responsebody += QLatin1String("<!DOCTYPE html>\r\n");
    tfetch(QVariantMap, blog);
  responsebody += QLatin1String("<html>\r\n<head>\r\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\r\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\r\n</head>\r\n<body>\r\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\r\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\r\n\r\n<h1>Editing Blog</h1>\r\n\r\n");
  responsebody += QVariant(formTag(urla("save", blog["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\r\n  <p>\r\n    <label>ID<br /><input type=\"text\" name=\"blog[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(blog["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\r\n  </p>\r\n  <p>\r\n    <label>Title<br /><input type=\"text\" name=\"blog[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(blog["title"]);
  responsebody += QLatin1String("\" /></label>\r\n  </p>\r\n  <p>\r\n    <label>Body<br /><input type=\"text\" name=\"blog[body]\" value=\"");
  responsebody += THttpUtility::htmlEscape(blog["body"]);
  responsebody += QLatin1String("\" /></label>\r\n  </p>\r\n  <p>\r\n    <input type=\"submit\" value=\"Save\" />\r\n  </p>\r\n</form>\r\n\r\n");
  responsebody += QVariant(linkTo("Show", urla("show", blog["id"]))).toString();
  responsebody += QLatin1String(" |\r\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_saveView)

#include "blog_saveView.moc"
