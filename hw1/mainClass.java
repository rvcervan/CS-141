class Shape
{

	String name;

	Shape(String newName)
	{
		name = newName;
	}

	String name()
	{
		return name;
	}
	

	double area()
	{
		return 0.0;
	}

	void draw()
	{
		System.out.println("Shape.draw() You should never see this.");
	}
}

class Triangle extends Shape
{
	int myHeight, myBase;	
	Triangle(String name, int h, int b)
	{
		super(name);
		myHeight = h;
		myBase = b;
		//System.out.println("now");
	}

	String name()
	{
		return name+"(" + myHeight+", "+myBase+") : ";
	}
	double area()
	{
		return .5 * myHeight * myBase;
	}
	
	void draw()
	{
		System.out.println("     *\n    * *\n   *   *\n  *     *\n *       *\n* * * * * *");
	}

}

class Square extends Shape
{
	int myHeight;

	Square(String name, int h)
	{
		super(name);
		myHeight = h;
	}

	String name()
	{
		return name+"("+myHeight+")"+" : ";
	}
	double area()
	{
		return myHeight * myHeight;
	}
	
	void draw()
	{
		System.out.println("* * * * * *\n*         *\n*         *\n*         *\n*         *\n* * * * * *");
	}
}

class Circle extends Shape
{
	int myRadius;
	double pi = 3.1415;
	
	Circle(String name, int r)
	{
		super(name);
		myRadius = r;
	}

	String name()
	{
		return name+"("+myRadius+")"+" : ";
	}
	double area()
	{
		return myRadius * myRadius * pi;
	}
	
	void draw()
	{
		System.out.println("  * * * *  \n*         *\n*         *\n*         *\n*         *\n  * * * *  ");
	}
}

class Rectangle extends Square
{
	int myWidth;

	Rectangle(String name, int h, int w)
	{
		super(name, h);
		myWidth = w;
	}
	String name()
	{
		return name+"("+myHeight+", "+myWidth+")"+" : ";
	}
	double area()
	{
		return myHeight * myWidth;
	}
	
	void draw()
	{
		System.out.println("* * * * * *\n*         *\n*         *\n*         *\n*         *\n*         *\n*         *\n* * * * * *");
	}
}

class ListNode
{
	Shape info;
	ListNode next;
	
	ListNode(Shape newInfo, ListNode newNext)
	{
		info = newInfo;
		next = newNext;
	}
}

class Picture
{
	ListNode head;

	void add(Shape sh)
	{
		head = new ListNode(sh, head);
	}

	void drawAll()
	{
		for (ListNode p = head; p != null; p = p.next)
		{
			p.info.draw();
			if (p.next == null || p.info.getClass() != p.next.info.getClass())
			{
				System.out.println();
			}
		}
	}
	

	void printShapes()
	{

		for (ListNode p = head; p != null; p = p.next)
		{
			System.out.println(p.info.name()+p.info.area());
			if (p.next == null || p.info.getClass() != p.next.info.getClass())
			{
				System.out.println();
			}
		}
		//System.out.println();
			
	}

	double totalArea()
	{
		double total = 0.0;
	
		for (ListNode p = head; p != null; p = p.next)
		{
			total = p.info.area() + total;
		}
		return total;
	}
}
		

public class mainClass
{

	static void println(double d)
	{
		System.out.println("Total: " + d);
	}

	public static void main(String args[])
	{
		Picture p = new Picture();
		
		p.add(new Rectangle("SecondRectangle", Integer.parseInt(args[0])-1, Integer.parseInt(args[1])-1));
		p.add(new Rectangle("FirstRectangle", Integer.parseInt(args[0]), Integer.parseInt(args[1])));

		p.add(new Square("SecondSquare", Integer.parseInt(args[0])-1 ));
		p.add(new Square("FirstSquare", Integer.parseInt(args[0])));

		p.add(new Circle("SecondCircle", Integer.parseInt(args[0])-1 ));
		p.add(new Circle("FirstCircle", Integer.parseInt(args[0])));

		p.add(new Triangle("SecondTriangle", Integer.parseInt(args[0])-1, Integer.parseInt(args[1])-1));
		p.add(new Triangle("FirstTriangle", Integer.parseInt(args[0]), Integer.parseInt(args[1])));
		
		p.printShapes();
		println(p.totalArea());
		System.out.println();
		p.drawAll();
	}
}





















