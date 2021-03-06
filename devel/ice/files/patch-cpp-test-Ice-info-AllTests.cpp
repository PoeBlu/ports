--- cpp.orig/test/Ice/info/AllTests.cpp	2011-06-15 21:43:59.000000000 +0200
+++ cpp/test/Ice/info/AllTests.cpp	2012-03-04 20:14:53.000000000 +0100
@@ -141,9 +141,11 @@
         test(info->adapterName.empty());
         test(info->localPort > 0);
         test(info->remotePort == 12010);
-        test(info->remoteAddress == defaultHost);
-        test(info->localAddress == defaultHost);
-
+        if (!inFreeBSDJail())
+        {
+            test(info->remoteAddress == defaultHost);
+            test(info->localAddress == defaultHost);
+        }
         ostringstream os;
 
         Ice::Context ctx = testIntf->getConnectionInfoAsContext();
@@ -163,8 +165,11 @@
         test(info->adapterName.empty());
         test(info->localPort > 0);
         test(info->remotePort == 12010);
-        test(info->remoteAddress ==defaultHost);
-        test(info->localAddress == defaultHost);
+        if (!inFreeBSDJail())
+        {
+            test(info->remoteAddress == defaultHost);
+            test(info->localAddress == defaultHost);
+        }
     }
     cout << "ok" << endl;
 
