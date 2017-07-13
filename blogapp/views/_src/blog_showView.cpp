#include <QtCore>
#include <TreeFrogView>
#include "blog.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_showView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  blog_showView() : TActionView() { }
  QString toString();
};

QString blog_showView::toString()
{
  responsebody.reserve(1657);
  responsebody += QLatin1String("<!DOCTYPE html>\r\n");
    tfetch(Blog, blog);
  responsebody += QLatin1String("<html>\r\n<head>\r\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\r\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\r\n</head>\r\n<body>\r\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\r\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\r\n\r\n<h1>Showing Blog</h1>\r\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.id());
  responsebody += QLatin1String("</dd><br />\r\n<dt>Title</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.title());
  responsebody += QLatin1String("</dd><br />\r\n<dt>Body</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.body());
  responsebody += QLatin1String("</dd><br />\r\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.createdAt());
  responsebody += QLatin1String("</dd><br />\r\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.updatedAt());
  responsebody += QLatin1String("</dd><br />\r\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.lockRevision());
  responsebody += QLatin1String("</dd><br />\r\n\r\n");
  responsebody += QVariant(linkTo("Edit", urla("save", blog.id()))).toString();
  responsebody += QLatin1String(" |\r\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\r\n\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_showView)

#include "blog_showView.moc"
