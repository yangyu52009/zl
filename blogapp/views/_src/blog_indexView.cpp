#include <QtCore>
#include <TreeFrogView>
#include "blog.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_indexView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  blog_indexView() : TActionView() { }
  QString toString();
};

QString blog_indexView::toString()
{
  responsebody.reserve(1707);
  responsebody += QLatin1String("<!DOCTYPE html>\r\n");
    responsebody += QLatin1String("<html>\r\n<head>\r\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\r\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\r\n</head>\r\n<body>\r\n\r\n<h1>Listing Blog</h1>\r\n\r\n");
  responsebody += QVariant(linkTo("Create a new Blog", urla("create"))).toString();
  responsebody += QLatin1String("<br />\r\n<br />\r\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\r\n  <tr>\r\n    <th>ID</th>\r\n    <th>Title</th>\r\n    <th>Body</th>\r\n  </tr>\r\n");
  tfetch(QList<Blog>, blogList);
  for (const auto &i : blogList) {
  responsebody += QLatin1String("  <tr>\r\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QLatin1String("</td>\r\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.title());
  responsebody += QLatin1String("</td>\r\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.body());
  responsebody += QLatin1String("</td>\r\n    <td>\r\n      ");
  responsebody += QVariant(linkTo("Show", urla("show", i.id()))).toString();
  responsebody += QLatin1String("\r\n      ");
  responsebody += QVariant(linkTo("Edit", urla("save", i.id()))).toString();
  responsebody += QLatin1String("\r\n      ");
  responsebody += QVariant(linkTo("Remove", urla("remove", i.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QLatin1String("\r\n    </td>\r\n  </tr>\r\n");
  };
  responsebody += QLatin1String("</table>\r\n\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_indexView)

#include "blog_indexView.moc"
