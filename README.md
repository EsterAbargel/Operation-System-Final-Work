# Operation-System-Final-Work
Following the Corona, instead of a exam we were asked to do a project

 
עבודת מסכמת : מערכות הפעלה 2020, סמסטר ב

שאלה 1:
מבנה הזכרון של תוכנית בשפת C. 
בשאלה זו תתנסו במבנה הזכרון  של תוכנית בשפת  C הכולל את הקטעים 	text, stack ,heap וכו'. נתונה התוכנית program. עליכם לענות על כל השאלות בהערות (comments). למטרה זו באפשרותכם להשתמש בכלים הבאים : 	objdump,  nm	,  size  (למדו איך להשתמש בהם). 
 
מה עליכם לבצע: 
      0)   למדו איך להשתמש ב- 	objdump,  nm	,  size . השתמשו ב - man  או מקורות אחרים לפי בחירתכם. 
עליכם להכיר את הכלים האלה לפחות ברמה שתאפשר לכם לבצע את המטלה. 
החליפו כל הערה (comment) שיש בה שאלה בתשובה, בתשובה של שורה אחת בתוך  התכנית המקורי ת.כל השאלות ממוספרות. שמרו על אותו מספור בתשובות שלכם. 
(1
יש ליצור קובץ pdf נפרד, שבו תסבירו כל אחת מתשובותיכם. כמו כן הוסיפו פלט של הכלים(הנ"ל) שהשתמשתם בהם, שמאשר את התשובה שלכם. יש להשתמש באותו מספור. לצורך נוחות הבדיקה, אנא העתיקו לפני כל תשובה את השאלה המקורית + שורת הקוד המתאימה מ התוכנית המקורי ת. 
(2
 
מה עליכם להגיש: 
1. תכנית C עם תשובות של שורה אחת מסעיף 1 שנקראת q1_<your_id>.c 2. קובץ pdf מסעיף 2 ששמו q1_<your_id>.pdf 
 

 
שאלה 2: signals 
 
המשימה שלכם היא לבדוק האם קיים תהליך (process) עם pid מסויים. דרך אחת היא להשתמש 
בשליחת  ( kill(<pid>, 0,  כאשר סיגנ ל 0 (zero signal) נתון ואפשר להשתמש בו. אם שליחת סיגנל 0 נכשלת עם הודעת שגיאה ESRCH, אנחנו יודעים שהתהליך אינו קיים. אם הקריאה נכשלה עם הודעת שגיאה EPERM (התהליך קיים אבל אין לנו הרשאה לשלוח לו סיגנל כזה) או מצליחה (אם יש לנו הרשאה לשלוח סיגנל כזה), אז אנחנו יודעים שהתהליך קיים. 
צריך להוסיף include errno.h כדי לקבל הודעות שגיאה כאלה. 
 
מה עליכם לבצע: 
0)	כתבו תכנית בשם check_pid.c  המקבלת פרמטר יחיד pid והפלט של התכנית הוא : 
 If EPERM, Process <pid> exists but we have no permission.	  If ESRCH, Process <pid>  does not exist. 
If kill is successful, Process <pid> exists. 
 
Running example: check_pid 2003 Process 2003 exists. 
 
1)	הציעו 2 שיטות נוספות לבדיקה הנ"ל. פרטו יתרונות וחסרונות של 3 השיטות הנ"ל. כתבו את תשובתכם בקובץ pdf נפרד בשם q21_<your_id>.pdf 
 
מה עליכם להגיש: 
check_pid.c,  makefile	 to compile, 	README	 how to run, and  	q21_<your_id>.pdf	 
 
 
2) בחלק זה תראו שמספר הסיגנלים המתקבלים יכול להיות קטן ממספר הסיגנלים שנשלחים. במילים אחרות, סיגנלים אינם נכנסים לתור. על מנת להראות זאת, כתבו 2 תכניות client.c ,server.c . ה-client יכול לשלוח 2 סוגים של סיגנלים: SIGINT,SIGUSR1. 
בתוך ה-server ה- handler של SIGINT סופר את מספר הסיגנלים SIGINT שמתקבלים. 
 ה-handler של SIGUSR1  מדפיס את מספר הסיגנלים  SIGINT שהגיעו ל-server. 
 ה- client מקבל 3 פרמטרים בסדר הבא: pid  של ה-server, מספר סיגנל 
                                                                                    SIGINT(2) או SIGUSR1(10)   :ומספר הסיגנלים שישלחו. לדוגמא
)1 client <server pid>  2 1000  
)2 client <server pid>  10 1 
 
בדוגמה הראשונה client ישל ח 1000 סיגנלים SIGINT  לשרת ע ם >server pid<. בדוגמה השניה השרת ע ם >server pid< ידפיס את מספר ה - SIGINT שהתקבל ו. מה עליכם לבצע: 
0)	כתבו את התכניות client.c ואת server.c המבצעות את מה שהוסבר. 
1)	עליכם להראות שלא כל הסיגנלים מתקבלים. 2) למדו על real time signals שנצברים לתור (	sigqueue,  sigaction	, etc). הסבירו את היתרונות והחסרונות של שתי השיטות. הוסיפו את ההסברים לקובץ q22_<your_id>.pdf. 
 
מה עליכם להגיש: 
client.c,  server.c	,  makefile	 how to compile, 	README	 how to run, and  	q22_<your_id>.pdf	. 
 
 
 
שאלה 3 (25 נק'): CPU scheduling בשאלה זו תתנסו בתזמון של CPU ב- Linux. 
 
מה עליכם לבצע: 
 
 עליכם ללמוד על הפקודות chrt, renice, taskset ב- Linux. לדוגמא, chrt  נועד לניהול פרמטרי זמן-אמת של התהליך. פקודה זו מחזירה או משנה את ערכי פרמטרי זמן-אמת של תהליך pid, או מריצה פקודה עם פרמטרים מסויימים. לצורך הלימוד תוכלו להשתמש ב- man או כל מקור אחר (למשל  כא ן). 
למדו איך אפשר לשנות את מדיניות התזמון והעדיפויות של תהליך. מה ההבדל בין chrt  ו- renice בתזמון CPU ? מה עושה taskset ? כמו כן עליכם להבין לפחות את מנגנוני התזמון הבאים: 
 .SCHED_DEADLINE, SCHED_FIFO, SCHED_IDLE, SCHED_RR, SCHED_OTHER	(1
 
 לאחר שהבנתם את הנדרש בסעיף 1 עליכם לכתוב תכנית בשם set_policy.c  שמגדירה מדיניות תזמון וקדימויות של תהליך. 	sched_setscheduler() system call משנה גם את מדיניות התזמון ואת הקדימויות של תהליך pid. אם pid=0, הפרמטרים של התהליך הקורא משתנים. 	(2
 SCHED_DEADLINE, מקבל 2 פרמטרים: מספר המייצג את אחת מהמדינויות (למשל Set_policy  המייצג integer ומספר (SCHED_FIFO, SCHED_IDLE, SCHED_RR, SCHED_OTHER  .עדיפות
 
מה עליכם להגיש: 
 set_policy.c	,  makefile	 to compile, 	README	 how to run, and  	q32_<your_id>.pdf	 containing	 output of commands confirming changed values. 

 
שאלה 4 (25 נק'): files in Linux בשאלה זו תעסקו בקבצים וה- metadata שלהם ב- Linux. 
 
 עליכם להבין את המושגים השונים בהקשר של מערכת הקבצים כגון: 
  .file descriptors, inods, directories,soft and hard links in Linux  .stat -של קובץ אפשר להשתמש ב metadata כדי לבדוק
כמו כן, עליכם להבין בכל הנושאים שעסקתם בהם במטלה  3. 	(1
 
 בחלק זה תשתמשו בפונקציה nftw(), המאפשרת לסרוק ספריה שלמה באופן רקורסיבי תוך ביצוע מספר פעולות (כגון קריאה לפונקציות המוגדרות ע"י המשתמש) לכל קובץ בעץ הקבצים. עליכם לכתוב תוכנית בשם dir_traversal.c  שעוברת באופן רקורסיבי על ספריה נתונה. על כל קובץ או ספריה התוכנית מדפיסה : סוג (לפי הדוגמא שבהמשך), מספר inode ושם. אם הספריה מכילה soft link, יש להתעלם ממנו. 	(2
 
Example:  
 
$ mkdir dir 
$ touch dir/a dir/b 
$ ln -s a dir/sl                                      ←- later	  ignored from the output	 
$ mkdir dir/sub 
$ touch dir/sub/x 
 
$ ./dir_traversal dir 
D 2327983 dir 
F 2327984 a 
F 2327985 b 
D 2327988 sub F 2327989 x  :מ ה עליכם להגישdir_traversal.c,  makefile	 to compile, 	README	 how to run, and  	q41_<your_id>.pdf	 containing the running output for the specified example.  :חשו ב

 
 
בהצלחה רבה ובריאות איתנה לכולם 
 
 
