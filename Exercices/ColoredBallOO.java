import java.awt.Color;

public class ColoredBallOO{
    private Vector posicao = new Vector(2);         // position
    private Vector velocidade = new Vector(2);         // velocity
    private final double raio;   // radius
    private final Color color;     // color

    //construtor de bola
    public ColoredBallOO(Vector p, Vector v, double r, Color c){
        posicao = p;
        velocidade = v;
        raio = r;
        color = c;
    }

    //retorna a posição
    public Vector pos(){
        return this.posicao;
    }

    //retorna a velocidade
    public Vector vel(){
        return this.velocidade;
    }

    //retorna o raio
    public double radius(){
        return this.raio;
    }

    //altera a velocidade
    public void setVel(Vector v){
        this.velocidade = v;
    }

    //altera a posição
    public void updatePosition(double dt){
        /*double[] c = {(this.posicao.cartesian(0) + dt*(this.velocidade.cartesian(0))), (this.posicao.cartesian(1) + dt*(this.velocidade.cartesian(1)))};
        Vector novaPos = new Vector(c);
        this.posicao = novaPos;*/

        this.posicao = this.posicao.plus(this.velocidade.scale(dt));

    }

    public void treatWalls(double size, double dt){
        double[] c = new double[2];
        if ((((this.posicao.cartesian(0) + dt*(this.velocidade.cartesian(0))) + this.raio) > size) || ((this.posicao.cartesian(0) + dt*(this.velocidade.cartesian(0))) + this.raio) < 10) c[0] = -(this.velocidade.cartesian(0));
        else c[0] = this.velocidade.cartesian(0);
        if ((((this.posicao.cartesian(1) + dt*(this.velocidade.cartesian(1))) + this.raio) > size) || ((this.posicao.cartesian(1) + dt*(this.velocidade.cartesian(1))) + this.raio) < 10) c[1] = -(this.velocidade.cartesian(1));
        else c[1] = this.velocidade.cartesian(1);

        this.velocidade = new Vector(c);
    }

    public void move(double size, double dt){
        this.treatWalls(size, dt);
        this.updatePosition(dt);
    }

    public void draw(){
        StdDraw.setPenColor(this.color);
        StdDraw.filledCircle(this.posicao.cartesian(0), this.posicao.cartesian(1), this.raio);
    }
}

