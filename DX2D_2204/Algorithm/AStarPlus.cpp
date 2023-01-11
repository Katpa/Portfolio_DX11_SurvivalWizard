#include "Framework.h"

AStarPlus::AStarPlus(InstancingMap* map)
    :AStar()
{
    map->GetNodes(nodes);
    SetEdge(map->GetWidth());

    heap = new Heap();

    SetRender();
}

AStarPlus::~AStarPlus()
{
}

void AStarPlus::SetRender()
{
    for (int i = 0; i<nodes.size(); i++)
    {
        nodes[i]->SetEdgePos(instances);
    }

}

void AStarPlus::SetEdge(UINT width)
{
    for (UINT i = 0; i < nodes.size(); i++)
    {
        UINT remainder = i % width;

        //������ ������ Ÿ�ϰ� ����
        if (remainder != width - 1) //�������� �ǳ��� �ƴѰ��
        {
            nodes[i]->AddEdge(nodes[i + 1]);
            nodes[i + 1]->AddEdge(nodes[i]);

            //����
            if (i < nodes.size() - (width * 2))
            {
                int tmp = nodes.size();
                if (nodes[i + width]->ReturnState() != Node::OBSTACLE &&
                    nodes[i + width + 1]->ReturnState() != Node::OBSTACLE)
                {
                    nodes[i]->AddEdge(nodes[i + (width * 2) + 1]);
                    nodes[i + (width * 2) + 1]->AddEdge(nodes[i]);
                }
            }
        }

        //������ �� ���� �ִ� ������ �����ϰ� ����
        if (i < nodes.size() - width)
        {
            nodes[i]->AddEdge(nodes[i + width]);
            nodes[i + width]->AddEdge(nodes[i]);

            //����
            if (remainder < width - 2)
            {
                if (nodes[i + 1]->ReturnState() != Node::OBSTACLE &&
                    nodes[i + width + 1]->ReturnState() != Node::OBSTACLE)
                {
                    nodes[i]->AddEdge(nodes[i + width + 2]);
                    nodes[i + width + 2]->AddEdge(nodes[i]);
                }
            }

            //���»�
            if (remainder > 1)
            {
                if (nodes[i - 1]->ReturnState() != Node::OBSTACLE &&
                    nodes[i + width - 1]->ReturnState() != Node::OBSTACLE)
                {
                    nodes[i]->AddEdge(nodes[i + width - 2]);
                    nodes[i + width - 2]->AddEdge(nodes[i]);
                }
            }
        }

        //��ĭ �밢��
        if (i < nodes.size() - width)
        {
            if (remainder != width - 1)
            {
                nodes[i]->AddEdge(nodes[i + width + 1]);
                nodes[i + width + 1]->AddEdge(nodes[i]);
            }

            if (remainder != 0)
            {
                nodes[i]->AddEdge(nodes[i + width - 1]);
                nodes[i + width - 1]->AddEdge(nodes[i]);
            }
        }

        //�����
        if (i < nodes.size() - (width * 2) && remainder > 0)
        {
            if (nodes[i + width]->ReturnState() != Node::OBSTACLE &&
                nodes[i + width - 1]->ReturnState() != Node::OBSTACLE)
            {
                nodes[i]->AddEdge(nodes[i + (width * 2) - 1]);
                nodes[i + (width * 2) - 1]->AddEdge(nodes[i]);
            }
        }
    }
}
