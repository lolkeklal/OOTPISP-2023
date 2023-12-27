using ConsoleApp2;

Builder builder1 = new UglyFaceBuilder();
Builder builder2 = new GoodFaceBuilder();
Builder builder3 = new SmileFaceBuilder();
Director director1 = new Director(builder1);
Product product1 = director1.Construct();
Director director2 = new Director(builder2);
Product product2 = director2.Construct();
Director director3 = new Director(builder3);
Product product3 = director3.Construct();
product1.Show();
product2.Show();
product3.Show(); 