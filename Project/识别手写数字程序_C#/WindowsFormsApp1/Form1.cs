using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1{
    public partial class Form1 : Form{
        public Form1(){
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e){

        }

        private Point p1, p2;
        private static bool drawing = false;
        int[,] s = new int[10, 10];
        List<Yangben> yb = new List<Yangben>();

        //开始与样本进行匹配
        private int calc_solve(){
            //关键代码
            int _max = -1, id=-1;
            double _maxsame = 0;
            string _c = "";
            for(int i = 0; i < yb.Count; i++) {
                double sa = yb[i].Sameas(s);
                _c += yb[i].val + " : " + sa + "\r\n";
                if (sa > _maxsame) {
                    _max = yb[i].val;
                    _maxsame = sa;
                    id = i;
                }
            }
            textBox1.Text = _c;
            return id;
        }
        //picture_画板鼠标落下
        private void pictureBox1_MouseDown_1(object sender, MouseEventArgs e){
            p1 = new Point(e.X, e.Y);
            p2 = new Point(e.X, e.Y);
            drawing = true;
        }
        //picture_画板鼠标移动
        private void pictureBox1_MouseMove_1(object sender, MouseEventArgs e){
            Graphics g = pictureBox1.CreateGraphics();
            if (e.Button == MouseButtons.Left){
                if (drawing){
                    //drawing = true;
                    Point currentPoint = new Point(e.X, e.Y);
                    g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;//消除锯齿
                    g.DrawLine(new Pen(Color.Red, 2), p2, currentPoint);

                    p2.X = currentPoint.X;
                    p2.Y = currentPoint.Y;

                    //统计像素
                    int tx, ty;
                    tx = e.X / 50;
                    ty = e.Y / 50;
                    if (tx >= 10) tx = 9; if (tx < 0) tx = 0;
                    if (ty >= 10) ty = 9; if (ty < 0) ty = 0;
                    s[ty,tx] = 1;

                    //记录极值
                    //uu = math.min(uu, e.y);
                    //ub = math.max(ub, e.y);
                    //ul = math.min(ul, e.x);
                    //ur = math.max(ur, e.y);
                }
            }
        }
        //picture_画板鼠标抬起
        private void pictureBox1_MouseUp_1(object sender, MouseEventArgs e){
            drawing = false;

            //几何拉伸
            //int[,] ss = new int[10, 10];
            //int tu = uu / 50, tb = ub / 50, tl = ul / 50, tr = ur / 50;
            //if (tu >= 10) tu = 9; if (tb >= 10) tb = 9; if (tl >= 10) tl = 9; if (tr >= 10) tr = 9;
            //int tw = tr - tl, th = tb - tu;
            //for (int i = tu; i <= tb; i++) {
            //    for(int j = tl; j <= tr; j++) {
            //        if(s[(i-tu)*(10/th), (j - tl) * (10 / tw)] == 1) {
            //            ss[]
            //        }
            //    }
            //}


            string sss = "";
            int c=calc_solve();
            if (c == -1) sss += "无答案";
            else sss += yb[c].val;
            label4.Text = sss;

            string co = "";
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    if (s[i, j] == 1)co += "◼";
                    else co += "◻";
                }
                co += "\n";
            }
            label2.Text = co;

            co = "";
            if(c!=-1)for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (yb[c].s[i, j] == 1) co += "◼";
                    else co += "◻";
                }
                co += "\n";
            }
            label3.Text = co;
        }
        //radio_控制台视图
        private void radioButton1_CheckedChanged(object sender, EventArgs e) {
            label2.Visible = false;
            label3.Visible = false;
            textBox1.Visible = true;
        }
        //radio_预览视图
        private void radioButton2_CheckedChanged(object sender, EventArgs e) {
            label2.Visible = true;
            label3.Visible = true;
            textBox1.Visible = false;
        }
        //button_学习按钮
        private void button2_Click(object sender, EventArgs e){
            int v = int.Parse(textBox2.Text);
            yb.Add(new Yangben(v,s));

            button1_Click_1(null,null);
        }
        //button_导出配置
        private void button3_Click(object sender, EventArgs e) {
            string co = "";
            for(int i = 0; i < yb.Count; i++) {
                if (i != 0) co += ",";
                co += "" + yb[i].val;
                for(int j = 0; j < 10; j++) {
                    int m = 0;
                    for(int k = 0; k < 10; k++) {
                        if (yb[i].s[j, k] == 1) m |= (1 << k);
                    }
                    co += "-"+ m;
                }
            }
            textBox1.Text = co;
        }
        //button_导入配置
        private void button4_Click(object sender, EventArgs e) {
            string ci = textBox1.Text;
            string[] fo;
            fo = ci.Split(',');
            for(int i = 0; i < fo.Length; i++) {
                string t = fo[i];
                string[] fot = t.Split('-');
                Yangben ybt = new Yangben();
                ybt.val = int.Parse(fot[0]);
                for(int j = 0; j < 10; j++) {
                    int foti = int.Parse(fot[j+1]);
                    for (int k = 0; k < 10; k++) {
                        if (((foti >> k) & 1) == 1) ybt.s[j, k] = 1;
                        else ybt.s[j, k] = 0;
                    }
                }
                yb.Add(ybt);
            }
        }
        //button_清除画板按钮
        private void button1_Click_1(object sender, EventArgs e){
            drawing = false;

            Graphics g = pictureBox1.CreateGraphics();
            g.Clear(Color.White);

            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    s[i, j] = 0;
                }
            }
        }
    }
    //样本类，用于记录样本，以及样本检验方法
    public class Yangben{
        public int[,] s = new int[10,10];
        public int val;
        public Yangben() { }
        public Yangben(int v,int[,] arg){
            s = new int[10, 10];
            for(int i = 0; i < 10; i++) {
                for(int j = 0; j < 10; j++) {
                    s[i, j] = arg[i, j];
                }
            }
            //s = arg;
            val = v;
        }
        public double Sameas(int[,] arg) {
            double sa = 0, sb = 0 ;
            for(int i = 0; i < 10; i++) {
                for(int j = 0; j < 10; j++) {
                    if (s[i, j] == 1 || arg[i, j] == 1) sb++;
                    if (s[i, j] == 1 && arg[i, j] == 1) sa++;
                    else {
                        int y1 = 0,y2 = 0;
                        for(int k1 = -1; k1 <= 1; k1++) {
                            if ((k1 == -1 && i == 0)||(k1 == 1 && i == 9)) continue;
                            for(int k2 = -1; k2 <= 1; k2++) {
                                if ((k2 == -1 && j == 0) || (k2 == 1 && j == 9)) continue;
                                if (s[i + k1, j + k2] == 1) { y1 = 1;}
                                if (arg[i + k1, j + k2] == 1) { y2 = 1; }
                            }
                        }
                        if (y1 == 1 && y2 == 1) {
                            sa += 0.3;
                        }
                    }
                }
            }
            return 1.0*sa/sb*100;
        }
    }
}
